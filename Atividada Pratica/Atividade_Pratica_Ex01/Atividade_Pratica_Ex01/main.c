#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "playlist.h"

int main()
{
	setlocale(LC_ALL, "");

	int pos, op, result;
	char musicRemove[30];

	// "*head" é um ponteito para "elemento de estrutura *List"
	//	Logo "*head" é um ponteiro para ponteiro
	List* head = createList();
	Playlist music;

	do
	{
		system("cls");
		printf("\t\t\t\t\t\t----------------\n");
		printf("\t\t\t\t\t\t| Sua Playlist |\n");
		printf("\t\t\t\t\t\t----------------\n");

		printf("\n\n1 - Insere no Inicio da Playlist\n");
		printf("2 - Insere no Final da Playlist\n");
		printf("3 - Insere no Meio da Playlist\n");
		printf("4 - Quantas Musicas há na sua Playlist\n");
		printf("5 - Remove uma Musica da Playlist\n");
		printf("6 - Mostra sua Playlist\n");
		printf("7 - Salva sua playlist \n");
		printf("8 - Deleta uma Playlist já Salva\n");
		printf("9 - Sair\n");
		printf("Digite sua Opção: ");
		scanf_s("%d", &op);

		switch (op)
		{
		case 1:
			
			buffer();
			printf("\n\nDigite o nome da banda ou artista: ");
			gets_s(music.nameBand, 29);

			printf("Digite o nome da musica: ");
			gets_s(music.nameMusic, 29);

			printf("Digite a duração da musica Ex: 3:36: ");
			gets_s(music.duration, 6);
			result = insertFist(head, music);

			if(result == 1)
				printf("\n\nMusica \"%s\" adicinada \n", music.nameMusic);
			system("pause>nul");
			system("cls");
			break;

		case 2:
			buffer();
			printf("\n\nDigite o nome da banda ou artista: ");
			gets_s(music.nameBand, 29);

			printf("Digite o nome da musica: ");
			gets_s(music.nameMusic, 29);
	
			printf("Digite a duração da musica Ex: 3:36: ");
			gets_s(music.duration, 6);

			result = insertFinal(head, music);
			if (result == 1)
				printf("\n\nMusica \"%s\" adicinada \n", music.nameMusic);
			system("pause>nul");
			system("cls");
			break;

		case 3:
			buffer();
			printf("\n\nDigite o nome da banda ou artista: ");
			gets_s(music.nameBand, 29);

			printf("Digite o nome da musica: ");
			gets_s(music.nameMusic, 29);

			printf("Digite a duração da musica Ex: 3:36: ");
			gets_s(music.duration, 6);

			printf("Digite a poscição que deseja inserir: ");
			scanf_s("%d", &pos);

			result = insertMiddle(head, music, pos);
			if (result == 1)
				printf("\n\nMusica \"%s\" adicinada \n", music.nameMusic);
			system("pause>nul");
			system("cls");
			break;

		case 4:
			printf("\n\n%d Musicas na playlist", sizeList(head));
			system("pause>nul");
			system("cls");
			break;

		case 5:
			buffer();
			printf("\n\nDigite o nome da musica que deseja remove: ");
			gets_s(musicRemove, 29);
			removeList(head, musicRemove);
			system("pause>nul");
			system("cls");
			break;

		case 6:
			printList(head);
			system("pause>nul");
			system("cls");
			break;

		case 7:
			saveFile(head);
			system("pause>nul");
			system("cls");
			break;

		case 8:
			removeFile();
			system("pause>nul");
			system("cls");
			break;

		case 9:
			freeList(head);
			exit(1);
			break;

		default:
			printf("\n\nEntrada Inválida\n");
			system("pause>nul");
			system("cls");
			break;
		}
	} while (1);

	return 0;
}
