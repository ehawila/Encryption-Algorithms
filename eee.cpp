//Elinor_Encryption_Engine (EEE)
//Developer: Eliyah Hawila
//Copyrights: Eliyah Hawila

#include <iostream>
#include <string>
#include <cctype>

std::string pass, epass;

void encrypt() {
  std::cout << "============================" << std::endl;
  std::cout << "Enter your password: ";
  std::cin >> pass;
  for (int i = 0; i <= pass.length(); i++) {
    //password element checkers
    bool is_sLetter = isalpha(pass[i]) && islower(pass[i]);
    bool is_cLetter = isalpha(pass[i]) && isupper(pass[i]);
    bool is__Number = isdigit(pass[i]);
    if (is_sLetter) {
      //rotate lower case letters by 13
      pass[i] = (pass[i] - 'a' + 13) % 26 + 'a';
      //rotate the new letters by 21
      pass[i] = (pass[i] - 'a' + 21) % 26 + 'a';
    }
    else if (is_cLetter) {
      //rotate upper case letters by 13
      pass[i] = (pass[i] - 'A' + 13) % 26 + 'A';
      //rotate the new letters by 21
      pass[i] = (pass[i] - 'A' + 21) % 26 + 'A';
    }
    else if (is__Number) {
      //increment digits by 1
      pass[i] = (pass[i] - '0' + 1) + '0';
    }
    else {
      //shift character forward by ascii value of 1
      pass[i] = pass[i] + 1;
    }
  }
  std::cout << "============================" << std::endl;
  std::cout << "Encryption: " << pass << std::endl;
  std::cout << "============================" << std::endl;
}

void decrypt() {
  std::cout << "============================" << std::endl;
  std::cout << "Enter your encryption: ";
  std::cin >> epass;
  for (int j = 0; j <= epass.length(); j++) {
    //password element checkers
    bool is_sLetter = isalpha(epass[j]) && islower(epass[j]);
    bool is_cLetter = isalpha(epass[j]) && isupper(epass[j]);
    bool is__Number = isdigit(epass[j]);
    if (is_sLetter) {
      //rotate lower case letters by 5
      epass[j] = (epass[j] - 'a' + 5) % 26 + 'a';
      //rotate the new letters by 13
      epass[j] = (epass[j] - 'a' + 13) % 26 + 'a';
    }
    else if (is_cLetter) {
      //rotate upper case letters by 5
      epass[j] = (epass[j] - 'A' + 5) % 26 + 'A';
      //rotate the new letters by 13
      epass[j] = (epass[j] - 'A' + 13) % 26 + 'A';
    }
    else if (is__Number) {
      //decrement digits by 1
      epass[j] = (epass[j] - '0' - 1) + '0';
    }
    else {
      //shift character backwards by ascii value of 1
      epass[j] = epass[j] - 1;
    }
  }
  std::cout << "============================" << std::endl;
  std::cout << "password: " << epass << std::endl;
  std::cout << "============================" << std::endl;
}

int main() {
  std::cout << "1. Encrypt" << std::endl;
  std::cout << "2. Decrypt" << std::endl;
  std::cout << "3. Exit" << std::endl;
  std::cout << "Select an option: ";
  int option;
  std::cin >> option;
  if (option == 1) {
    encrypt();
  }
  else if (option == 2) {
    decrypt();
  }
  else if (option == 3) {
    exit(1);
  }
  else {
    std::cout << "============================" << std::endl;
    std::cout << "Invalid option, try again" << std::endl;
    std::cout << "============================" << std::endl;
    main();
  }
  return 0;
}
