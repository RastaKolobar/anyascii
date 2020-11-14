# AnyAscii [![build](https://travis-ci.org/anyascii/anyascii.svg?branch=master)](https://travis-ci.org/anyascii/anyascii)

Unicode to ASCII transliteration

[**Web Demo**](https://anyascii.com)

#### Table of Contents

* [Description](#description)
[Examples](#examples)
* [Implementations](#implementations):
[Go](#go)
[Java](#java)
[JavaScript](#javascript)
[Julia](#julia)
[PHP](#php)
[Python](#python)
[Ruby](#ruby)
[Rust](#rust)
[Shell](#shell)
[.NET](#net)
* [Background](#background)
[Unidecode](#unidecode)
[Sources](#sources)

## Description

Converts Unicode text to a reasonable representation using only ASCII.

For most characters in Unicode, AnyAscii provides an ASCII-only replacement string.
Text is converted character-by-character without considering the context.
The mappings for each script are based on popular existing romanization schemes.
Symbolic characters are converted based on their meaning or appearance.
All ASCII characters in the input are left unchanged,
every other character is replaced with printable ASCII characters.
Unknown characters are removed.

## Examples

Representative examples for different languages comparing the AnyAscii output to the conventional romanization.

|Language (Script)|Input|Output|Conventional|
|---|---|---|---|
|French (Latin)|René François Lacôte|Rene Francois Lacote|Rene Francois Lacote|
|German (Latin)|Blöße|Blosse|Bloesse|
|Vietnamese (Latin)|Trần Hưng Đạo|Tran Hung Dao|Tran Hung Dao|
|Norwegian (Latin)|Nærøy|Naeroy|Naroy|
|Ancient Greek (Greek)|Φειδιππίδης|Feidippidis|Pheidippides|
|Modern Greek (Greek)|Δημήτρης Φωτόπουλος|Dimitris Fotopoylos|Dimitris Fotopoulos|
|Russian (Cyrillic)|Борис Николаевич Ельцин|Boris Nikolaevich El'tsin|Boris Nikolayevich Yeltsin|
|Ukrainian (Cyrillic)|Володимир Горбулін|Volodimir Gorbulin|Volodymyr Horbulin|
|Bulgarian (Cyrillic)|Търговище|T'rgovishche|Targovishte|
|Mandarin Chinese (Han)|深圳|ShenZhen|Shenzhen|
|Cantonese Chinese (Han)|深水埗|ShenShuiBu|Sham Shui Po|
|Korean (Hangul)|화성시|HwaSeongSi|Hwaseong-si|
|Korean (Han)|華城市|HuaChengShi|Hwaseong-si|
|Japanese (Hiragana)|さいたま|saitama|Saitama|
|Japanese (Han)|埼玉県|QiYuXian|Saitama-ken|
|Amharic (Ethiopic)|ደብረ ዘይት|debre zeyt|Dobre Zeyit|
|Tigrinya (Ethiopic)|ደቀምሓረ|dek'emhare|Dekemhare|
|Arabic|دمنهور|dmnhwr|Damanhur|
|Armenian|Աբովյան|Abovyan|Abovyan|
|Georgian|სამტრედია|samt'redia|Samtredia|
|Hebrew|אברהם הלוי פרנקל|'vrhm hlvy frnkl|Abraham Halevi Fraenkel|
|Unified English Braille (Braille)|⠠⠎⠁⠽⠀⠭⠀⠁⠛|+say x ag|Say it again|
|Bengali|ময়মনসিংহ|mymnsimh|Mymensingh|
|Burmese (Myanmar)|ထန်တလန်|thntln|Thantlang|
|Gujarati|પોરબંદર|porbmdr|Porbandar|
|Hindi (Devanagari)|महासमुंद|mhasmumd|Mahasamund|
|Kannada|ಬೆಂಗಳೂರು|bemgluru|Bengaluru|
|Khmer|សៀមរាប|siemrab|Siem Reap|
|Lao|ສະຫວັນນະເຂດ|sahvannaekhd|Savannakhet|
|Malayalam|കളമശ്ശേരി|klmsseri|Kalamassery
|Odia|ଗଜପତି|gjpti|Gajapati|
|Punjabi (Gurmukhi)|ਜਲੰਧਰ|jlmdhr|Jalandhar|
|Sinhala|රත්නපුර|rtnpur|Ratnapura|
|Tamil|கன்னியாகுமரி|knniyakumri|Kanniyakumari|
|Telugu|శ్రీకాకుళం|srikakulm|Srikakulam|
|Thai|สงขลา|sngkhla|Songkhla|

|Symbols|Input|Output|
|---|---|---|
|Emojis|😎 👑 🍎|`:sunglasses: :crown: :apple:`|
|Misc.|☆ ♯ ♰ ⚄ ⛌|* # + 5 X|
|Letterlike|№ ℳ ⅋ ⅍|No M & A/S|

## Implementations

### Go

https://pkg.go.dev/github.com/anyascii/go

```go
import "github.com/anyascii/go"

s := anyascii.Transliterate("άνθρωποι")
// anthropoi
```

Go 1.10+ compatible

### <a name="java"></a> Java [![jitpack](https://img.shields.io/jitpack/v/github/anyascii/anyascii)](https://jitpack.io/#com.anyascii/anyascii)

https://jitpack.io/#com.anyascii/anyascii

```java
String s = AnyAscii.transliterate("άνθρωποι");
// anthropoi
```

Java 6+ compatible

### <a name="javascript"></a> JavaScript [![npm](https://img.shields.io/npm/v/any-ascii)](https://npmjs.com/package/any-ascii)

https://npmjs.com/package/any-ascii

```javascript
// Node.js
const anyAscii = require('any-ascii');

const s = anyAscii('άνθρωποι');
// anthropoi
```

`npm install any-ascii`

### Julia

https://github.com/anyascii/AnyAscii.jl

```julia
julia> using AnyAscii
julia> anyascii("άνθρωποι")
"anthropoi"
```

Julia 1.0+ compatible

`pkg> add AnyAscii`

### PHP <a name="php"></a> [![packagist](https://img.shields.io/packagist/v/anyascii/anyascii)](https://packagist.org/packages/anyascii/anyascii)

https://packagist.org/packages/anyascii/anyascii

```php
$s = AnyAscii::transliterate('άνθρωποι');
// anthropoi
```

PHP 5.3+ compatible

`composer require anyascii/anyascii`

### <a name="python"></a> Python [![pypi](https://img.shields.io/pypi/v/anyascii)](https://pypi.org/project/anyascii)

https://pypi.org/project/anyascii

```python
from anyascii import anyascii

s = anyascii('άνθρωποι')
assert s == 'anthropoi'
```

Python 3.3+ compatible

`pip install anyascii`

### <a name="ruby"></a> Ruby [![gem](https://img.shields.io/gem/v/any_ascii)](https://rubygems.org/gems/any_ascii)

https://rubygems.org/gems/any_ascii

```ruby
require 'any_ascii'

s = AnyAscii.transliterate('άνθρωποι')
# anthropoi
```

Ruby 2.0+ compatible

`gem install any_ascii`

### <a name="rust"></a> Rust [![crates.io](https://img.shields.io/crates/v/any_ascii)](https://crates.io/crates/any_ascii)

https://crates.io/crates/any_ascii

```rust
use any_ascii::any_ascii;

let s = any_ascii("άνθρωποι");
// anthropoi
```

Rust 1.36+ compatible

Install:
```toml
# Cargo.toml
[dependencies]
any_ascii = "*"
```

Install executable: `cargo install any_ascii`

```console
$ anyascii άνθρωποι
anthropoi

$ echo άνθρωποι | anyascii
anthropoi
```

### <a name="shell"></a> Shell

https://raw.githubusercontent.com/anyascii/anyascii/master/sh/anyascii

```console
$ anyascii άνθρωποι
anthropoi

$ echo άνθρωποι | anyascii
anthropoi
```

POSIX-compliant

### <a name="net"></a> .NET [![nuget](https://img.shields.io/nuget/v/AnyAscii)](https://nuget.org/packages/AnyAscii)

https://nuget.org/packages/AnyAscii

```cs
// C#
using AnyAscii;

string s = "άνθρωποι".Transliterate();
// anthropoi
```

## Background

> Unicode is the foundation for text in all modern software:
> it’s how all mobile phones, desktops, and other computers represent the text of every language.
> People are using Unicode every time they type a key on their phone or desktop computer, and every time they look at a web page or text in an application.
> [*](https://www.unicode.org/reports/tr51/#Encoding)

[Unicode](https://en.wikipedia.org/wiki/Unicode) is the universal character set, a global standard to support all the world's languages.
It contains 140,000+ characters used by 150+ scripts along with various symbols.
Typically encoded into bytes using [UTF-8](https://en.wikipedia.org/wiki/UTF-8).

[ASCII](https://en.wikipedia.org/wiki/ASCII) is the most compatible character set, established in 1967.
It is a subset of Unicode and UTF-8 consisting of 128 characters.
The [printable](https://en.wikipedia.org/wiki/ASCII#Printable_characters) characters are English letters, digits, and punctuation,
with the remaining being [control characters](https://en.wikipedia.org/wiki/ASCII#Control_characters).
The characters found on a standard US keyboard correspond to the printable ASCII characters.

> ... expressed only in the original non-control ASCII range so as to be as widely compatible with as many existing tools, languages, and serialization formats as possible and avoid display issues in text editors and source control.
> [*](https://spec.graphql.org/June2018/#sec-Source-Text)

A language is written using characters from a [script](https://en.wikipedia.org/wiki/Writing_system).
A script can be [alphabetic](https://en.wikipedia.org/wiki/Alphabet), [logographic](https://en.wikipedia.org/wiki/Logogram), or [syllabic](https://en.wikipedia.org/wiki/Syllabary).
Some languages use multiple scripts and some scripts are used by multiple languages.
The [Latin script](https://en.wikipedia.org/wiki/Latin_script) is used in English and many other languages.

When converting text between languages there are multiple properties that can be preserved:
- Meaning: [Translation](https://en.wikipedia.org/wiki/Translation)
- Sound: [Transcription](https://en.wikipedia.org/wiki/Orthographic_transcription)
- Spelling: [Transliteration](https://en.wikipedia.org/wiki/Transliteration)

[Romanization](https://en.wikipedia.org/wiki/Romanization) is the conversion into the Latin script using transliteration and transcription.
Romanization is most commonly used when representing the names of people and places.

> Geographical names are Romanized to help foreigners find the place they intend to go to and help them remember cities, villages and mountains they visited and climbed.
> But it is Koreans who make up the Roman transcription of their proper names to print on their business cards and draw up maps for international tourists.
> Sometimes, they write the lyrics of a Korean song in Roman letters to help foreigners join in a singing session or write part of a public address (in Korean) in Roman letters for a visiting foreign VIP.
> In this sense, it is for both foreigners and the local public.
> The Romanization system must not be a code only for the native English-speaking community here but an important tool for international communication between Korean society, foreign residents in the country and the entire external world.
> [*](https://web.archive.org/web/20070927204130/http://www.korea.net/korea/kor_loca.asp?code=A020303)

## Unidecode

AnyAscii is an alternative to (and inspired by) [Unidecode](https://metacpan.org/pod/Text::Unidecode) and its many [ports](https://github.com/search?q=unidecode).
Unidecode was created in 2001 and only supports the [basic mulitlingual plane](https://en.wikipedia.org/wiki/Plane_(Unicode)#Basic_Multilingual_Plane).
AnyAscii gives better results, supports more than twice as many characters, and often has a smaller file size.
For a complete comparison between AnyAscii and Unidecode see `table.tsv` and `unidecode/table.tsv`.

## Sources

[ALA-LC](https://www.loc.gov/catdir/cpso/roman.html),
[BGN/PCGN](https://www.gov.uk/government/publications/romanization-systems),
[Discord](https://github.com/anyascii/discord-emojis),
[ISO](https://www.iso.org/ics/01.140.10/x/p/1/u/1/w/1/d/1),
[KNAB](https://www.eki.ee/knab/kblatyl2.htm),
[UNGEGN](https://www.eki.ee/wgrs/),
[Unihan](https://unicode.org/reports/tr38/),
national standards,
and more.

> Romanization systems approved for application to geographic names may prove similarly applicable to personal names and to text and have frequently been used for such purposes. [*](https://assets.publishing.service.gov.uk/government/uploads/system/uploads/attachment_data/file/921738/INTRODUCTION.pdf)
