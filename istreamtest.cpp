#include <iostream>
#include <string>

int main(){
    std::string s;
    std::cin >> s;

    char peek = std::cin.rdbuf() -> snextc();
    if (std::cin.fail()) std::cout << "Failed";
    std::cout << "�� ��° �ܾ� �� �ձ��� : " << peek << std::endl;
    std::cin >> s;
    std::cout << "�ٽ� ������ : " <<  s << std::endl;
}
