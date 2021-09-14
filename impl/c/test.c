#include <locale.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uchar.h>
#include "anyascii.h"

void anyascii_string(const char *in, char *out) {
	uint_least32_t cp;
	size_t cu;
	const char *r;
	while ((cu = mbrtoc32(&cp, in, 4, 0))) {
		size_t rlen = anyascii(cp, &r);
		memcpy(out, r, rlen);
		in += cu;
		out += rlen;
	}
	*out = 0;
}

char *actual;

void check(const char *s, const char *expected) {
	anyascii_string(s, actual);
	if (strcmp(actual, expected)) {
		printf("%s != %s\n", actual, expected);
		exit(1);
	}
}

void checkcp(uint_least32_t utf32, const char *expected) {
	const char *r;
	size_t rlen = anyascii(utf32, &r);
	if (strlen(expected) != rlen || strncmp(r, expected, rlen)) {
		printf("%x -> %.*s != %s\n", utf32, (int) rlen, r, expected);
		exit(1);
	}
}

int main() {
	setlocale(LC_ALL, "en_US.utf8");
	actual = malloc(256);

	check("sample", "sample");

	checkcp(0x0080, "");
	checkcp(0x00ff, "y");
	checkcp(0xe000, "");
	checkcp(0xfdff, "");
	checkcp(0x000e0020, " ");
	checkcp(0x000e007e, "~");
	checkcp(0x000f0000, "");
	checkcp(0x000f0001, "");
	checkcp(0x0010ffff, "");
	checkcp(0x00110000, "");
	checkcp(0x7fffffff, "");
	checkcp(0x80000033, "");
	checkcp(0xffffffff, "");

	check("René François Lacôte", "Rene Francois Lacote");
	check("Blöße", "Blosse");
	check("Trần Hưng Đạo", "Tran Hung Dao");
	check("Nærøy", "Naeroy");
	check("Φειδιππίδης", "Feidippidis");
	check("Δημήτρης Φωτόπουλος", "Dimitris Fotopoylos");
	check("Борис Николаевич Ельцин", "Boris Nikolaevich El'tsin");
	check("Володимир Горбулін", "Volodimir Gorbulin");
	check("Търговище", "T'rgovishche");
	check("深圳", "ShenZhen");
	check("深水埗", "ShenShuiBu");
	check("화성시", "HwaSeongSi");
	check("華城市", "HuaChengShi");
	check("さいたま", "saitama");
	check("埼玉県", "QiYuXian");
	check("ደብረ ዘይት", "debre zeyt");
	check("ደቀምሓረ", "dek'emhare");
	check("دمنهور", "dmnhwr");
	check("Աբովյան", "Abovyan");
	check("სამტრედია", "samt'redia");
	check("אברהם הלוי פרנקל", "'vrhm hlvy frnkl");
	check("⠠⠎⠁⠽⠀⠭⠀⠁⠛", "+say x ag");
	check("ময়মনসিংহ", "mymnsimh");
	check("ထန်တလန်", "thntln");
	check("પોરબંદર", "porbmdr");
	check("महासमुंद", "mhasmumd");
	check("ಬೆಂಗಳೂರು", "bemgluru");
	check("សៀមរាប", "siemrab");
	check("ສະຫວັນນະເຂດ", "sahvannaekhd");
	check("കളമശ്ശേരി", "klmsseri");
	check("ଗଜପତି", "gjpti");
	check("ਜਲੰਧਰ", "jlmdhr");
	check("රත්නපුර", "rtnpur");
	check("கன்னியாகுமரி", "knniyakumri");
	check("శ్రీకాకుళం", "srikakulm");
	check("สงขลา", "sngkhla");
	check("😎 👑 🍎", ":sunglasses: :crown: :apple:");
	check("☆ ♯ ♰ ⚄ ⛌", "* # + 5 X");
	check("№ ℳ ⅋ ⅍", "No M & A/S");

	check("トヨタ", "toyota");
	check("ߞߐߣߊߞߙߌ߫", "konakri");
	check("𐬰𐬀𐬭𐬀𐬚𐬎𐬱𐬙𐬭𐬀", "zarathushtra");
	check("ⵜⵉⴼⵉⵏⴰⵖ", "tifinagh");
	check("𐍅𐌿𐌻𐍆𐌹𐌻𐌰", "wulfila");
	check("ދިވެހި", "dhivehi");
	
	return 0;
}
