#include <iostream>
#include <bitset>

// Отримання значення біта
bool getBit(int num, int bitIndex) {
    return (num & (1 << bitIndex)) != 0;
}

// Вмикання біта
int setBit(int num, int bitIndex) {
    return num | (1 << bitIndex);
}

// Вимикання біта
int clearBit(int num, int bitIndex) {
    return num & ~(1 << bitIndex);
}

// Обмін значень двох цілих чисел за допомогою бітової арифметики
void swap(int &a, int &b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

// Конвертер з бітового представлення у десятковий
int binToDec(std::string binary) {
    return std::bitset<32>(binary).to_ulong();
}

// Конвертер з десяткового представлення у бітове
std::string decToBin(int decimal) {
    return std::bitset<32>(decimal).to_string();
}

// Шифр Цезаря з використанням операції XOR
std::string encrypt(std::string text, int s) {
    std::string result = "";

    // Перебігаємо всі символи
    for (int i=0; i<text.length(); i++)
    {
        result += text[i] ^ s;
    }

    return result;
}

int main() {
    int num = 9;
    int bitIndex = 1;
    int num2 = 15;
    std::string bin = "1010";
    int dec = 10;
    std::string text = "HELLO";
    int s = 3;

    std::cout << "Bit " << bitIndex << " of number " << num << " is " << getBit(num, bitIndex) << "\n";
    std::cout << "Number " << num << " after setting bit " << bitIndex << " is " << setBit(num, bitIndex) << "\n";
    std::cout << "Number " << num << " after clearing bit " << bitIndex << " is " << clearBit(num, bitIndex) << "\n";

    std::cout << "Swapping " << num << " and " << num2 << "...\n";
    swap(num, num2);
    std::cout << "Now the first number is " << num << ", and the second number is " << num2 << "\n";

    std::cout << "The decimal equivalent of binary " << bin << " is " << binToDec(bin) << "\n";
    std::cout << "The binary equivalent of decimal " << dec << " is " << decToBin(dec) << "\n";

    std::string encryptedText = encrypt(text, s);
    std::cout << "Encrypted text is " << encryptedText << "\n";
    std::cout << "Decrypted text is " << encrypt(encryptedText, s) << "\n";

    return 0;
}