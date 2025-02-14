package com.anyascii.build.gen

import com.anyascii.build.deflate
import java.nio.file.Path
import kotlin.io.path.createDirectories
import kotlin.io.path.writeBytes

fun ruby(g: Generator) {
    val dirPath = Path.of("impl/ruby/lib/data")
    dirPath.toFile().deleteRecursively()
    dirPath.createDirectories()

    for ((blockNum, block) in g.blocks) {
        val s = block.noAscii().joinToString("\t")
        dirPath.resolve("%03x".format(blockNum)).writeBytes(deflate(s))
    }
}