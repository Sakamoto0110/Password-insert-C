#include <string.h>
#include <conio.h>
#include <windows.h>

int tamanhoSenha;
char password[20];
char temp;
COORD coord;
coord.X = 0;
coord.Y = 0;

while((temp = getch()) != '\r') // Pega o caractere
    {
        if ( temp != '\b')
        {
                putchar('*'); // Insere visualmente o caractere
        }
        if ( temp == 8) // Se precionar backspace
        {
            if ( tamanhoSenha != 0 ) // Se a senha nao for nula
            {
                // 21 é o tamanho do texto printado na tela antes de começar a ler o que sera digitado.
                coord.X = 21 + (tamanhoSenha-1); // Define o X para uma casa anterior
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // Coloca o cursor uma casa anterior
                cout << ' '; // Apaga
                password[tamanhoSenha-1] = ' '; // Apaga do vetor, se existir
                tamanhoSenha--; // Reduz o tamanho do vetor
                coord.X = 21 + (tamanhoSenha); // Posiciona o X no final da senha
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // Posiciona o cursor no final da senha
            }
        }
        if ( (temp >= 'a' || temp <= 'z' || temp >= 0 || temp <= 9) && temp != '\b' && temp != 8 )
        {
            password[tamanhoSenha] = temp; // Insere o carctere na variavel senha
            tamanhoSenha++;
        }
    }
