#!/bin/sh

set -eux
cd -- "$(dirname -- "${BASH_SOURCE:-$0}")"

check() {
	test "$("$shell" anyascii "$1")" = "$2"
}

shells='sh bash dash zsh yash posh mksh rbash rzsh ksh93'
for shell in $shells
do
	if command -v $shell
	then
		check "" ""
		check "	 ~" "	 ~"
		check "sample" "sample"
		check "René François Lacôte" "Rene Francois Lacote"
		check "Großer Hörselberg" "Grosser Horselberg"
		check "Trần Hưng Đạo" "Tran Hung Dao"
		check "Nærøy" "Naeroy"
		check "Φειδιππίδης" "Feidippidis"
		check "Δημήτρης Φωτόπουλος" "Dimitris Fotopoylos"
		check "Борис Николаевич Ельцин" "Boris Nikolaevich El'tsin"
		check "Володимир Горбулін" "Volodimir Gorbulin"
		check "Търговище" "T'rgovishche"
		check "دمنهور" "dmnhwr"
		check "אברהם הלוי פרנקל" "'vrhm hlvy frnkl"
		check "ߞߐߣߊߞߙߌ߫" "konakri"
		check "სამტრედია" "samt'redia"
		check "Աբովյան" "Abovyan"
		check "สงขลา" "sngkhla"
		check "ສະຫວັນນະເຂດ" "sahvannaekhd"
		check "សៀមរាប" "siemrab"
		check "ထန်တလန်" "thntln"
		check "深圳" "ShenZhen"
		check "深水埗" "ShenShuiBu"
		check "화성시" "HwaSeongSi"
		check "華城市" "HuaChengShi"
		check "さいたま" "saitama"
		check "埼玉県" "QiYuXian"
		check "トヨタ" "toyota"
		check "ደብረ ዘይት" "debre zeyt"
		check "ደቀምሓረ" "dek'emhare"
		check "⠠⠎⠁⠽⠀⠭⠀⠁⠛" "+say x ag"
		check "ময়মনসিংহ" "mymnsimh"
		check "પોરબંદર" "porbmdr"
		check "महासमुंद" "mhasmumd"
		check "ಬೆಂಗಳೂರು" "bemgluru"
		check "കളമശ്ശേരി" "klmsseri"
		check "ਜਲੰਧਰ" "jlmdhr"
		check "ଗଜପତି" "gjpti"
		check "රත්නපුර" "rtnpur"
		check "கன்னியாகுமரி" "knniyakumri"
		check "శ్రీకాకుళం" "srikakulm"
		check "😎 👑 🍎" ":sunglasses: :crown: :apple:"
		check "☆ ♯ ♰ ⚄ ⛌" "* # + 5 X"
		check "№ ℳ ⅋ ⅍" "No M & A/S"
	else
		echo "skipping $shell"
	fi
done

echo success
