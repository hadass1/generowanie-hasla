#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
    void personal_data(string& name, string& surname){
        cout << "Podaj imie: ";
        cin >> name;
        cout<< "Podaj nazwisko: ";
        cin>> surname;
        cout<<name<<" "<<surname<<endl;
}

    string choose(int& chosen_number, string& chosen_position){
        string positions[3] = {"Tester", "Kierownik", "Pracownik"};
        cout<<"Wybierz stanowisko: 1 - Tester, 2 - Kierownik, 3 - Pracownik: ";
        cin>>chosen_number;
        chosen_position = positions[chosen_number - 1];
        cout<<chosen_position<<endl;
        return chosen_position;
}

    int big_small(string&  yes_and_no, int& big_small_true){
        cout<<"Male oraz duze litery? t-tak/n-nie: ";
        cin>>yes_and_no;
        if (yes_and_no == "t" || yes_and_no == "T"){
            cout<<"Tak"<<endl;
            big_small_true=1;
        }else if(yes_and_no == "n" || yes_and_no == "N"){
            cout<<"Nie"<<endl;
            big_small_true=0;
        }

}

    int numbers(string&  yes_and_no, int& numbers_true){
        cout<<"Cyfry?t-tak/n-nie: ";
        cin>>yes_and_no;
        if (yes_and_no == "t" || yes_and_no == "T"){
            cout<<"Tak"<<endl;
            numbers_true=1;
        }else if(yes_and_no == "n" || yes_and_no == "N"){
            cout<<"Nie"<<endl;
            numbers_true=0;
        }
}


    int special_characters(string&  yes_and_no, int& special_characters_true){
        cout<<"Znaki specialne?t-tak/n-nie: ";
        cin>>yes_and_no;
        if (yes_and_no == "t" || yes_and_no == "T"){
            cout<<"Tak"<<endl;
            special_characters_true = 1;
        } else if(yes_and_no == "n" || yes_and_no == "N"){
            cout<<"Nie"<<endl;
            special_characters_true = 0;
        }
    }

    string gen_pas (int big_small_true, int numbers_true, int special_characters_true, int n_characters){
        int random_letters, random_numbers, random_chars;
        srand( time( NULL ));
        string characters_1 = "!@#$%^&*?";
        string letters = "abcdefghijklmnopqrstuwvxyz";
        string big_letters ="ABCDEFGHIJKLMNOPQRSTUWVXYZ";
        string numbers_1 = "0123456789";
        string pas_elements = "";
        string password;

        if(big_small_true == 1) {
            random_letters = rand() % 10;
            pas_elements += letters;
            random_letters = rand() % 10;
            pas_elements += big_letters;
        } else {
            random_letters = rand() % 10;
            pas_elements += letters;
        }
        if(numbers_true == 1) {
            random_numbers = rand() % 10;
            pas_elements += numbers_1;
        }
        if(special_characters_true == 1) {
            random_chars = rand() % 10;
            pas_elements += characters_1;
        }
        for(int i=0;i<n_characters;i++){
            random_numbers = rand() % pas_elements.length();
            password += pas_elements[random_numbers];
        }
        return password;
    }

int main()
{
    string name, surname;

    int chosen_number;
    string chosen_position;
    int n_characters;
    string yes_and_no;
    int numbers_true;
    int big_small_true;
    int special_characters_true;
    string password;
    string positions;
    personal_data(name, surname);
    cout<<endl;
    choose(chosen_number, chosen_position);
    cout<<endl;
    big_small(yes_and_no, big_small_true);
    cout<<endl;
    numbers(yes_and_no, numbers_true);
    cout<<endl;
    special_characters(yes_and_no, special_characters_true);
    cout<<endl;
    cout<< "Podaj ilosc znakow: ";
    cin>> n_characters;
    cout<<n_characters<<endl;
    password = gen_pas(big_small_true, numbers_true, special_characters_true, n_characters);
    cout<<name<<" "<<surname<<" "<<chosen_position<<" "<<"haslo: "<<password;



    return 0;
}
