newaction {
    trigger = "clean",
    description = "Remove all generated build files",
    execute = function()
        os.execute("git clean -fdX")
    end,
}
