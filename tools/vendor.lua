local upstream_dir = path.getabsolute("../vendor/upstream")

function upstream(relative)
    return path.join(upstream_dir, relative)
end

