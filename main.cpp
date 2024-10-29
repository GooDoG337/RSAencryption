#include <iostream>
#include "longone.h"
#include <random>
using shishik4life::longone;
using std::cout;

longone FastPow(const longone& num, const longone& default_one, const longone& N, longone pow) {
    longone temp;
    if(pow == 1) {
        temp = default_one;
    }
    else if(pow.isEven()) {
        temp =  FastPow(num, default_one, N, pow/2);
        temp = (temp * temp)%N;
    }
    else {
        temp = (FastPow(num, default_one, N, pow/2));
        temp = ((temp * temp)*default_one)%N;
    }
    return temp;
}

int main() {
    std::vector<longone> const nums = {
{"370791604769783808000000000000000000000000000000000000000000000000000000000000001"},
{"997991983811983709971859443709641919857829593757839691359883929337977577239877821"},
{"1191784525501486285440151324690893587467306703332577794205081610382957543058510401"},
{"8914423337761098715972584418167651094617711286574636875025121393196418317811514229"},
{"11111111111111111111111111111111111111116661111111111111111111111111111111111111111"},
{"14361817905487073108115025320764062442342597502003905253144371337891157457030439301"},
{"72173736552996866735119796485956768945999371377377779713333793171797133971739117999"},
{"77777777777777777777777777777777777777772227777777777777777777777777777777777777777"},
{"100000000000000000000000000000000000000000000000000000000000000000000000000000000027"},
{"100000000000009999999999999900000000000000999999999999990000000000000099999999999999"},
{"104495676331778315966103878903450701989608781073244439950619431748912396904023371773"},
{"133333333333333333333333333333333333333333333333333333333333333333333333333333333333"},
{"1559144712891223110910871021929883839727659613569547479457389367277233211975331"},
{"2468101214161820222426283032343638404244464850525456586062646668707274767880827"},
{"3511173141596783109127157179191211241277283331353367401431461509547563587599617"},
{"3705346855594118253554271520278013051304639509300498049262642688253220148477691"},
{"5210644015679228794060694325390955853335898483908056458352183851018372555735221"},
{"5997706410301399683467831356763914486624944745669403968229086821699091536281599"},
{"6100000000000000000000000000000000000000000000000000000000000000000000000000019"},
{"7777777777777777777777777777777777777778777777777777777777777777777777777777777"},
{"8888888888888888888888888888888888888888888888888888888888888888888888888888881"},
{"11698896101111181609619689808818888906916986100111111691188119616009611966996889"},
{"22537211232223552133332272923531222223112175722333721931322254123743221133522347"},
{"100078829100078487100078457100078399100078379100077569100076729100076659100075799"},
{"111111111111111111111111111111111111111161111111111111111111111111111111111111111"},
{"122222221212222212221222122222121222222212222222121222221222122212222212122222221"},
{"144224957030740838232163831078010958839186925349935057754641619454168759682999733"},
{"199109681199089061198998881198969611198891991198888601198816811198668191198610801"},
{"265358979323846264338327950288419716939937510582097494459230781640628620899862803"},
{"333333333322222223325555523325777523325777523325777523325555523322222223333333333"},
{"333383333333383333333383333333383333888888888333383333333383333333383333333383333"},
{"531872289054204184185084734375133399408303613982130856645299464930952178606045848877129147820387996428175564228204785846141207532462936339834139412401975338705794646595487324365194792822189473092273993580587964571659678084484152603881094176995594813302284232006001752128168901293560051833646881436219"}
    };
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, nums.size()-1); // define the range
    const int p_index = distr(gen);
    longone p = nums[p_index];
    int q_index = distr(gen);
    while(q_index == p_index) {
        q_index = distr(gen);
    }
    longone q = nums[q_index];
    cout << "p: " << p << '\n';
    cout << "q: " << q << '\n';
    const longone Fi = (p-1)*(q-1);
    cout << "Fi = " << Fi << '\n';

    const longone N = p*q;
    cout << "N = " << N << '\n';

    const longone e = 691;
    cout << "e = " << e << '\n';

    longone d = 1;
    for(longone k = 1; d%e; k++) {
        d = ((k*Fi)+1);
    }
    d= d/e;
    cout << "d = " << d << '\n';

    std::string message;
    std::vector<longone> v;
    cout << "Enter message:";
	std::getline(std::cin, message);
    for(const char& elm:message) {
        v.push_back( FastPow(elm, elm, N, e));
        std::cout << v[v.size()-1] << '\n'; //Если не переносить строку, он, похоже, буферизирует все cout-ы, чтоб вывести всё после окончания цикла, что может дать ложное предположение что программа зависла.
    }
    message.clear();
    for(const longone& elm:v) {
        std::cout << char(FastPow(elm, elm, N, d)) << '\n'; //То же самое, что на строке 56
    }
    return 0;
}
