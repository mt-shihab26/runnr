premake.api.register { name = "clangd", scope = "config", kind = "boolean" }

premake.override(premake.main, "postAction", function(base)
    base()

    if _ACTION == "clean" then
        return
    end

    for wks in premake.global.eachWorkspace() do
        for prj in premake.workspace.eachproject(wks) do
            local cfg = premake.project.getconfig(prj, "debug")
            if not cfg.clangd then
                goto continue
            end

            local flags = { "-xc++" }
            if cfg.language == "C" then
                flags = { "-xc" }
            end

            local dialect = cfg.language == "C" and cfg.cdialect or cfg.cppdialect
            if dialect then
                table.insert(flags, "-std=" .. dialect:lower())
            end

            for _, dir in ipairs(cfg.includedirs) do
                table.insert(flags, "-I" .. path.getrelative(prj.basedir, dir))
            end
            for _, dir in ipairs(cfg.externalincludedirs) do
                table.insert(flags, "-isystem" .. path.getrelative(prj.basedir, dir))
            end

            if cfg.warnings == "Extra" then
                table.insert(flags, "-Wall")
                table.insert(flags, "-Wextra")
            end

            for _, define in ipairs(cfg.defines) do
                table.insert(flags, "-D" .. define)
            end

            local file = path.join(prj.basedir, "compile_flags.txt")
            io.writefile(file, table.concat(flags, "\n") .. "\n")
            printf("Generated %s...", path.getrelative(os.getcwd(), file))

            ::continue::
        end
    end
end)
