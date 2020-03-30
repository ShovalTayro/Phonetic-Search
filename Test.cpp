/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Uriya Havshush, Shoval Tayro>
 * 
 * Date: 2020-03
 */

#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;


TEST_CASE("Test replacement of p and b") {
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "    happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
}

TEST_CASE("Test replacement of c,k,q") {
    string text = "cook cookie";
    CHECK(find(text, "qooc") == string("cook"));
    CHECK(find(text, "kooc") == string("cook"));
    CHECK(find(text, "kooq") == string("cook"));
    CHECK(find(text, "kooqie") == string("cookie"));
    CHECK(find(text, "qoocie") == string("cookie"));
    CHECK(find(text, "qookie") == string("cookie"));
}

TEST_CASE("Test replacement of v and w") {
    string text = "we want a good view";
    CHECK(find(text, "ve") == string("we"));
    CHECK(find(text, "Vand") == string("want"));
    CHECK(find(text, "wiev") == string("view"));
    CHECK(find(text, "joot") == string("good"));
}

TEST_CASE("Test replacement of g and j") {
    string text = "Game of the great journey";
    CHECK(find(text, "game") == string("Game"));
    CHECK(find(text, "Jame") == string("Game"));
    CHECK(find(text, "Jread") == string("great"));
    CHECK(find(text, "Guornei") == string("journey"));
}

TEST_CASE("Test replacement of d and t") {
    string text = "do what they want";
    CHECK(find(text, "to") == string("do"));
    CHECK(find(text, "tu") == string("do"));
    CHECK(find(text, "vhad") == string("what"));
    CHECK(find(text, "dhei") == string("they"));
    CHECK(find(text, "wand") == string("want"));
}

TEST_CASE("Test replacement of o and u") {
    string text = "our journey is beautiful";
    CHECK(find(text, "uur") == string("our"));
    CHECK(find(text, "juornei") == string("journey"));
    CHECK(find(text, "beaotiful") == string("beautiful"));
    CHECK(find(text, "beautifol") == string("beautiful"));
    CHECK(find(text, "beaodypol") == string("beautiful"));
}

TEST_CASE("Test replacement of i and y") {
    string text = "this is my dream";
    CHECK(find(text, "thys") == string("this"));
    CHECK(find(text, "ys") == string("is"));
    CHECK(find(text, "yz") == string("is"));
    CHECK(find(text, "mi") == string("my"));
    CHECK(find(text, "dhyz") == string("this"));
}

TEST_CASE("Test replacement of s and z") {
    string text = "soup with schizophrenetic zebra ";
    CHECK(find(text, "zuop") == string("soup"));
    CHECK(find(text, "zouf") == string("soup"));
    CHECK(find(text, "sebra") == string("zebra"));
    CHECK(find(text, "zchizophrenetic") == string("schizophrenetic"));
    CHECK(find(text, "Zchisophrenetic") == string("schizophrenetic"));
    CHECK(find(text, "schisophrenetic") == string("schizophrenetic"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
}
TEST_CASE("Test replacement and lower-upper caseof all kinds") {
    string text = "We are about to learn cpp";
    CHECK(find(text, "cfb") == string("cpp"));
    CHECK(find(text, "kff") == string("cpp"));
    CHECK(find(text, "Du") == string("to"));
    CHECK(find(text, "abuOD") == string("about"));
}

TEST_CASE("Test replacement & lower-case and upper-case of all kinds") {
    string text = "Implementation of Phonetic Search";
    CHECK(find(text, "ymblemendatiun") == string("Implementation"));
    CHECK(find(text, "uB") == string("of"));
    CHECK(find(text, "bhUnediq") == string("Phonetic"));
    CHECK(find(text, "fhonedyk") == string("Phonetic"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "we use clang ";
    CHECK(find(text, "Ve") == string("we"));
    CHECK(find(text, "ose") == string("use"));
    CHECK(find(text, "KlanG") == string("clang"));
    CHECK(find(text, "qlanJ") == string("clang"));
}

TEST_CASE("Test all kind of problems") {
    string text = "What is your name ";
    CHECK(find(text, "vhat") == string("What"));
    CHECK(find(text, "Vhad") == string("What"));
    CHECK(find(text, "Iz") == string("is"));
    CHECK(find(text, "ys") == string("is"));
    CHECK(find(text, "iuor") == string("your"));
    CHECK(find(text, "Your") == string("your"));
    CHECK(find(text, "Yuor") == string("your"));
    CHECK(find(text, "IouR") == string("your"));
}

TEST_CASE("Test all kind of problems") {
    string text = "Our names are Shoval and Uriya ";
    CHECK(find(text, "uOr") == string("Our"));
    CHECK(find(text, "namez") == string("names"));
    CHECK(find(text, "oor") == string("Our"));
    CHECK(find(text, "zhuwal") == string("Shoval"));
    CHECK(find(text, "zHoWal") == string("Shoval"));
    CHECK(find(text, "anT") == string("and"));
    CHECK(find(text, "Oriya") == string("Uriya"));
    CHECK(find(text, "Uryia") == string("Uriya"));
    CHECK(find(text, "oryIa") == string("Uriya"));
}

TEST_CASE("Test all kind of problems") {
    string text = "Where is your job ";
    CHECK(find(text, "vhere") == string("Where"));
    CHECK(find(text, "yS") == string("is"));
    CHECK(find(text, "Yz") == string("is"));
    CHECK(find(text, "iuor") == string("your"));
    CHECK(find(text, "IOuR") == string("your"));
    CHECK(find(text, "gub") == string("job"));
    CHECK(find(text, "GOb") == string("job"));
    CHECK(find(text, "Gof") == string("job"));
    CHECK(find(text, "guf") == string("job"));
    CHECK(find(text, "juP") == string("job"));
    CHECK(find(text, "jOP") == string("job"));
}

TEST_CASE("Test all kind of problems") {
    string text = "Israel check point ";
    CHECK(find(text, "ysrael") == string("Israel"));
    CHECK(find(text, "Yzrael") == string("Israel"));
    CHECK(find(text, "khekc") == string("check"));
    CHECK(find(text, "KheqQ") == string("check"));
    CHECK(find(text, "CheqK") == string("check"));
    CHECK(find(text, "Boind") == string("point"));
    CHECK(find(text, "fuynd") == string("point"));
    CHECK(find(text, "puynD") == string("point"));
    CHECK(find(text, "puInT") == string("point"));
}

TEST_CASE("Test all kind of problems") {
    string text = "Where do you live";
    CHECK(find(text, "vhere") == string("Where"));
    CHECK(find(text, "VhERE") == string("Where"));
    CHECK(find(text, "tu") == string("do"));
    CHECK(find(text, "DO") == string("do"));
    CHECK(find(text, "tO") == string("do"));
    CHECK(find(text, "iou") == string("you"));
    CHECK(find(text, "YOU") == string("you"));
    CHECK(find(text, "YuO") == string("you"));
    CHECK(find(text, "lyve") == string("live"));
}

TEST_CASE("Test exception cases") {
    string text = "We live in Israel";
    CHECK_THROWS(find(text, ""));
    CHECK_THROWS(find(text, "We live"));
    CHECK_THROWS(find(text, "Israe"));
    CHECK_THROWS(find(text, "hello"));
    CHECK_THROWS(find(text, "hello world"));
    CHECK_THROWS(find(text, " "));
    CHECK_THROWS(find(text, "ive"));
    CHECK_THROWS(find(text, "w"));
}
