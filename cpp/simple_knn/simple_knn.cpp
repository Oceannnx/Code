#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const int nearest = 5;
const int people_count = 52;
struct Data{
    string name = "";
    double ne = 0, ni = 0, te = 0, ti = 0, se = 0, si = 0, fe = 0, fi= 0;
    string mbti = "";
    string nickname = "";
    double distance = 9999;
};

double get_Distance(Data a, Data b){
    double dist = 0;
    dist += pow(a.ne - b.ne, 2);
    dist += pow(a.ni - b.ni, 2);
    dist += pow(a.te - b.te, 2);
    dist += pow(a.ti - b.ti, 2);
    dist += pow(a.se - b.se, 2);
    dist += pow(a.si - b.si, 2);
    dist += pow(a.fe - b.fe, 2);
    dist += pow(a.fi - b.fi, 2);
    return sqrt(dist);
}

void get_mbti(Data myself, Data data[]){
    int e=0 ,ie=0 ,s=0 ,n=0 ,t=0 ,f=0 ,j=0 ,p=0 ;
    char temp[4];
    for(int i=0; i<nearest; i++){
        cout << "The nerest MBTI : " << setw(7) << left << data[i].nickname  << " : " << setw(7) << left << data[i].mbti << " : " << setw(7) << left << data[i].distance << endl;
        ((data[i].mbti)[0] == 'e' or (data[i].mbti)[0] == 'E') ? e+=1 : ie+=1;
        ((data[i].mbti)[1] == 's' or (data[i].mbti)[1] == 'S') ? s+=1 : n+=1;
        ((data[i].mbti)[2] == 't' or (data[i].mbti)[2] == 'T') ? t+=1 : f+=1;
        ((data[i].mbti)[3] == 'j' or (data[i].mbti)[3] == 'J') ? j+=1 : p+=1;
    }
    (e < ie) ? temp[0] = 'I' : temp[0] = 'E';
    (s < n) ? temp[1] = 'N': temp[1] = 'S';
    (t < f) ? temp[2] = 'F' : temp[2] = 'T';
    (j < p) ? temp[3] = 'P' : temp[3] = 'J';
    myself.mbti = temp;
    cout << "Your MBTI is : " << myself.mbti << endl;
}

void get_nearest_data(Data data[], Data nearest_data[]){
    Data temp;
    for(int i=0; i<people_count; i++){
        if(data[i].distance < nearest_data[4].distance){
            nearest_data[4] = {data[i].name, data[i].ne, data[i].ni, data[i].te, data[i].ti, data[i].se, data[i].si, data[i].fe, data[i].fi, data[i].mbti, data[i].nickname, data[i].distance};
            if(nearest_data[4].distance < nearest_data[3].distance){
                temp = {nearest_data[3].name, nearest_data[3].ne, nearest_data[3].ni, nearest_data[3].te, nearest_data[3].ti, nearest_data[3].se, nearest_data[3].si, nearest_data[3].fe, nearest_data[3].fi, nearest_data[3].mbti, nearest_data[3].nickname, nearest_data[3].distance};
                nearest_data[3] = {nearest_data[4].name, nearest_data[4].ne, nearest_data[4].ni, nearest_data[4].te, nearest_data[4].ti, nearest_data[4].se, nearest_data[4].si, nearest_data[4].fe, nearest_data[4].fi, nearest_data[4].mbti, nearest_data[4].nickname, nearest_data[4].distance};
                nearest_data[4] =  {temp.name, temp.ne, temp.ni, temp.te, temp.ti, temp.se, temp.si, temp.fe, temp.fi, temp.mbti, temp.nickname, temp.distance};
                if(nearest_data[3].distance < nearest_data[2].distance){
                    temp = {nearest_data[2].name, nearest_data[2].ne, nearest_data[2].ni, nearest_data[2].te, nearest_data[2].ti, nearest_data[2].se, nearest_data[2].si, nearest_data[2].fe, nearest_data[2].fi, nearest_data[2].mbti, nearest_data[2].nickname, nearest_data[2].distance};
                    nearest_data[2] = {nearest_data[3].name, nearest_data[3].ne, nearest_data[3].ni, nearest_data[3].te, nearest_data[3].ti, nearest_data[3].se, nearest_data[3].si, nearest_data[3].fe, nearest_data[3].fi, nearest_data[3].mbti, nearest_data[3].nickname, nearest_data[3].distance};
                    nearest_data[3] =  {temp.name, temp.ne, temp.ni, temp.te, temp.ti, temp.se, temp.si, temp.fe, temp.fi, temp.mbti, temp.nickname, temp.distance};
                    if(nearest_data[2].distance < nearest_data[1].distance){
                        temp = {nearest_data[1].name, nearest_data[1].ne, nearest_data[1].ni, nearest_data[1].te, nearest_data[1].ti, nearest_data[1].se, nearest_data[1].si, nearest_data[1].fe, nearest_data[1].fi, nearest_data[1].mbti, nearest_data[1].nickname, nearest_data[1].distance};
                        nearest_data[1] = {nearest_data[2].name, nearest_data[2].ne, nearest_data[2].ni, nearest_data[2].te, nearest_data[2].ti, nearest_data[2].se, nearest_data[2].si, nearest_data[2].fe, nearest_data[2].fi, nearest_data[2].mbti, nearest_data[2].nickname, nearest_data[2].distance};
                        nearest_data[2] =  {temp.name, temp.ne, temp.ni, temp.te, temp.ti, temp.se, temp.si, temp.fe, temp.fi, temp.mbti, temp.nickname, temp.distance};
                        if(nearest_data[1].distance < nearest_data[0].distance){
                            temp = {nearest_data[0].name, nearest_data[0].ne, nearest_data[0].ni, nearest_data[0].te, nearest_data[0].ti, nearest_data[0].se, nearest_data[0].si, nearest_data[0].fe, nearest_data[0].fi, nearest_data[0].mbti, nearest_data[0].nickname, nearest_data[0].distance};
                            nearest_data[0] = {nearest_data[1].name, nearest_data[1].ne, nearest_data[1].ni, nearest_data[1].te, nearest_data[1].ti, nearest_data[1].se, nearest_data[1].si, nearest_data[1].fe, nearest_data[1].fi, nearest_data[1].mbti, nearest_data[1].nickname, nearest_data[1].distance};
                            nearest_data[1] =  {temp.name, temp.ne, temp.ni, temp.te, temp.ti, temp.se, temp.si, temp.fe, temp.fi, temp.mbti, temp.nickname, temp.distance};
                        }
                    }
                }   
            }
        }
    }
}

int main()
{
    double distance[people_count];

    Data myself;
    // myself = {"Santijit Kamnak", 32, 32, 27, 36, 29, 31, 28, 23,  "", "Ono"};
    // myself = {"Santijit Kamnak", 24.8, 19.2, 25, 30, 22, 28, 19, 25, "", "Ono"};
    // myself = {"Santijit Kamnak",  22.4, 29.6, 26, 26, 26, 30, 22, 25, "", "Ono"};
    // myself = {"Santijit Kamnak", 33, 33.6, 25, 29, 25, 28, 35, 34, "", "Ono"};
    cout << "Enter your info : ";
    cin >> myself.ne >> myself.ni >> myself.te >> myself.ti >> myself.se >> myself.si >> myself.fe >> myself.fi;
    // cout <<  myself.ne << " " << myself.ni << " " << myself.te << " " << myself.ti << " " << myself.se << " " << myself.si << " " <<myself.fe << " " <<myself.fi;



    Data data[people_count];
    data[0] = {"Warin Wattanapornprom", 32, 32, 27, 36, 29, 31, 28, 23, "INTJ", "Aj.Yong"};
    data[1] = {"Kornkanok  Welagert", 28.4, 29.4, 29, 34, 27, 24, 23, 21, "ISTP", "Somchun"};
    data[2] = {"Kunakron Tana", 30, 24, 25, 27, 23, 28, 26, 17, "ENTP", "Title"};
    data[3] = {"Chinnapt Sukthong", 30, 24, 25, 27, 23, 28, 26, 17, "ISTJ", "Nai"};
    data[4] = {"Chinavat Nachaithong", 35.6, 37.8, 27, 28, 28, 29, 36, 35, "ENFP", "Mon"};
    data[5] = {"Teekamon Chaiwongwutikul", 23.4, 26, 27, 30, 28, 31, 26, 21, "ISTJ", "Queen"};
    data[6] = {"Dollatham Charoethammkic", 37, 47.8, 43, 47, 47, 45, 37, 43, "INTJ", "Oat"};
    data[7] = {"Thiyada Kittiwithitkun", 34, 26.6, 26, 29, 28, 34, 33, 32, "ESFJ", "Por"};
    data[8] = {"Thidarat Sitthidech", 29, 31.2, 26, 27, 17, 32, 33, 26, "INFJ", "Louknam"};
    data[9] = {"Phumiphat Santithawornying", 26.2, 28.6, 21, 25, 30, 31, 32, 20, "INFJ", "Phu"};
    data[10] = {"Manotham Damnoen", 35.4, 29.4, 26, 28, 28, 19, 29, 27, "ENTP", "Auan"};
    data[11] = {"Wachirawit Intapan", 29, 25, 21, 23, 32, 36, 14, 19, "INTP", "Guy"};
    data[12] = {"Warit Teerapong", 35.8, 28.4, 28, 32, 18, 32, 31, 35, "INFP", "Smart"};
    data[13] = {"Sasima Phanta", 20.4, 22.4, 32, 32, 24, 28, 25, 16, "ESTJ", "Ja"};
    data[14] = {"Artima Rojanagamonson", 34.8, 28, 35, 32, 26, 32, 28, 17, "ESTJ", "Belle"};
    data[15] = {"Koraphan Manitha", 22.4, 31.4, 33, 34, 33, 35, 25, 23, "INTP", "Riw"};
    data[16] = {"Ganyawee Sanghom", 34.4, 36.8, 24, 32, 28, 35, 32, 34, "INFP", "Pearwa"};
    data[17] = {"Kimhan Jongjaidee", 38.2, 32.2, 35, 34, 17, 28, 28, 18, "ENTP", "Kim"};
    data[18] = {"Chaithawat Saklang", 24.8, 24.6, 29, 26, 29, 28, 29, 29, "ESFP", "Art"};
    data[19] = {"Nattanischa Aumpornchairuch", 29.2, 23.8, 28, 30, 22, 31, 32, 21, "ESTJ", "Love"};
    data[20] = {"Thanapong Simmanee", 23.4, 30.8, 35, 41, 31, 36, 39, 29, "ISFJ", "Yu"};
    data[21] = {"Thidarut Deeramies", 31.6, 36.4, 24, 32, 32, 30, 24, 20, "ISTP", "Aum"};
    data[22] = {"Panachai Suvimolopas", 34.2, 24.6, 31, 35, 33, 25, 32, 25, "ENTP", "Bank"};
    data[23] = {"Pattanapol Saelim", 41.8, 37.8, 28, 21, 34, 34, 33, 23, "ENTP", "Jaylerr"};
    data[24] = {"Pichayut Sombat", 32.2, 25.2, 29, 27, 30, 31, 25, 26, "INTP", "Field"};
    data[25] = {"Poomthai Promkote ", 39.6, 46.8, 33, 36, 32, 36, 30, 30, "INTP", "Poom"};
    data[26] = {"Lalhada Suttiprapha", 27.8, 23.4, 21, 27, 24, 35, 26, 22, "ISFJ", "Pleng"};
    data[27] = {"Kantinan Kuikeaw", 13.8, 16, 33, 31, 35, 32, 23, 16, "ESTJ", "Fig"};
    data[28] = {"Chothanin Thitisrirat", 29.8, 28, 24, 26, 29, 32, 36, 18, "ESFJ", "Maithong"};
    data[29] = {"Yanisa Mungkarotai", 23, 26.6, 28, 25, 17, 29, 29, 31, "INTJ", "Zom"};
    data[30] = {"Jessada Pranee", 27.8, 24.2, 32, 29, 18, 20, 13, 31, "INTP", "Jack"};
    data[31] = {"Suphanut Chanroong", 27.8, 24.2, 32, 29, 18, 20, 13, 31, "ENFP", "Beck"};
    data[32] = {"Keerataphan Malai", 15.6, 28.2, 21, 31, 19, 28, 18, 23, "ISTP", "New"};
    data[33] = {"Thanachot Wongyai", 24.8, 19.2, 25, 30, 22, 28, 19, 25, "INTP", "Sian"};
    data[34] = {"Pawinnarut Pornpanarat", 47.4, 31.2, 36, 32, 36, 37, 29, 31, "ENTP", "Captain"};
    data[35] = {"Phirada Chemmanmud", 23.6, 22.2, 28, 35, 27, 40, 23, 22, "ISTJ", "Aida"};
    data[36] = {"Phattawee Witthayapanyanont", 37.2, 23.6, 36, 39, 34, 33, 31, 16, "INTP", "Jai"};
    data[37] = {"Sathapana Tinop", 23.2, 30.6, 30, 36, 19, 21, 4, 28, "INTP", "Guy"};
    data[38] = {"Nuttasit Tannitipaisal", 33., 34.4, 24, 24, 31, 35, 32, 25, "ENTP", "Nut"};
    data[39] = {"Nut Somwang", 19.6, 19.2, 25, 32, 36, 30, 20, 17, "ESTJ", "Guy"};
    data[40] = {"Pattarachanon Uraiwichaikul", 35.6, 28.4, 36, 38, 36, 28, 29, 30, "ESTJ", "Deaw"};
    data[41] = {"Krantharat Ratchart", 26.6, 21, 27, 27, 25, 26, 22, 19, "ESTJ", "Tennis"};
    data[42] = {"Pasin Laopooti", 32.8, 31, 28, 37, 29, 38, 25, 29, "INTP", "Jane"};
    data[43] = {"Patchnida Hemwannanukul", 29.8, 23.4, 30, 26, 27, 30, 29, 29, "ESTJ", "Pin"};
    data[44] = {"Nakamon Yongpaisarn", 28, 24, 31, 31, 29, 37, 28, 28, "INFP", "Be"};
    data[45] = {"Atchima Nateepradap", 17.6, 22.2, 28, 25, 20, 35, 27, 18, "ISTJ", "Aut"};
    data[46] = {"Natthapon Tanateeraanan", 24.6, 22, 32, 32, 36, 38, 35, 27, "ESTP", "Nutsu"};
    data[47] = {"Naphatchanun Suecey", 23.4, 26, 31, 33, 24, 27, 31, 21, "ESFJ", "Hong"};
    data[48] = {"Narutchai Mauensaen", 33.2, 27, 32, 28, 33, 32, 39, 40, "INFP", "FLUK"};
    data[49] = {"Natchapon Ponlaem", 33.6, 32, 34, 31, 31, 37, 36, 29, "ESFJ", "Two"};
    data[50] = {"Phacharaphon Aiamphan", 36.4, 36.4, 34, 32, 31, 31, 37, 29, "INTP", "Folk"};
    data[51] = {"Sarita Tongsawat", 33, 33.6, 25, 29, 25, 28, 35, 34, "INFJ", "Gam"};
    // data[14] = {"Santijit Kamnak", 22.4, 29.6, 26, 26, 26, 30, 22, 25, "ISTP", "Ono"};

    Data nearest_data[5];
    for(int i=0; i<5; i++){
        nearest_data[i] = {"", 0, 0, 0, 0, 0, 0, 0, 0, "", ""};
    }
    for (int i = 0; i < people_count; i++){
        data[i].distance = get_Distance(myself, data[i]);
    }
    get_nearest_data(data, nearest_data);
    get_mbti(myself,nearest_data);
}


//// Santijit Kamnak 65090500457

