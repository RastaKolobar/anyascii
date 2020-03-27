package com.hunterwb.anyascii.build

import com.fasterxml.jackson.module.kotlin.jacksonObjectMapper
import java.io.File

private val EMOJI_BLACKLIST = "©®‼⁉™Ⓜ㊗㊙🈁🈂🈚🈯🈲🈳🈴🈵🈶🈷🈸🈹🈺🉐🉑".codePointsArray().asList()

fun emojis() = jacksonObjectMapper()
        .readTree(File("input/discord-emojis.json"))
        .flatten()
        .filter { it["surrogates"].asText().codePointsArray().dropLastWhile { it == 0xfe0f }.size == 1 }
        .associateTo(Table()) { it["surrogates"].asText().codePointAt(0) to it["names"].first().asText().let { ":$it:" } }
        .minus(EMOJI_BLACKLIST)