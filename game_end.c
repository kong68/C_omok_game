int game_end(int(*Board)[19]) {
	int i;
	int j;
	for (i = 2; i < 18; i++) {
		for (j = 0; j < 20; j++) {
			if (Board[j][i - 2] == 1 && Board[j][i - 1] == 1 && Board[j][i] == 1 && Board[j][i + 1] == 1 && Board[j][i + 2] == 1) {

				printf("¼±°ø ½Â¸®");

				return 1;
			}
			else if (Board[j][i - 2] == -1 && Board[j][i - 1] == -1 && Board[j][i] == -1 && Board[j][i + 1] == -1 && Board[j][i + 2] == -1) {

				printf("ÈÄ°ø ½Â¸®");

				return 1;
			}
		}
	}
	for (i = 2; i < 18; i++) {
		for (j = 0; j < 20; j++) {

			if (Board[i - 2][j] == 1 && Board[i - 1][j] == 1 && Board[i][j] == 1 && Board[i + 1][j] == 1 && Board[i + 2][j] == 1) {

				printf("¼±°ø ½Â¸®");

				return 1;
			}
			else if (Board[i - 2][j] == -1 && Board[i - 1][j] == -1 && Board[i][j] == -1 && Board[i + 1][j] == -1 && Board[i + 2][j] == -1) {

				printf("ÈÄ°ø ½Â¸®");

				return 1;
			}
		}
	}


	for (i = 2; i < 18; i++) {
		for (j = 2; j < 18; j++) {
			if (Board[j - 2][i - 2] == 1 && Board[j - 1][i - 1] == 1 && Board[j][i] == 1 && Board[j + 1][i + 1] == 1 && Board[j + 2][i + 2] == 1) {

				printf("¼±°ø ½Â¸®");

				return 1;
			}
			else if (Board[j - 2][i - 2] == -1 && Board[j - 1][i - 1] == -1 && Board[j][i] == -1 && Board[j + 1][i + 1] == -1 && Board[j + 2][i + 2] == -1) {
				printf("ÈÄ°ø ½Â¸®");

				return 1;
			}
		}
	}

	for (i = 2; i < 18; i++) {
		for (j = 2; j < 18; j++) {

			if (Board[j + 2][i - 2] == 1 && Board[j + 1][i - 1] == 1 && Board[j][i] == 1 && Board[j - 1][i + 1] == 1 && Board[j - 2][i + 2] == 1) {

				printf("¼±°ø ½Â¸®");

				return 1;
			}
			else if (Board[j + 2][i - 2] == -1 && Board[j + 1][i - 1] == -1 && Board[j][i] == -1 && Board[j - 1][i + 1] == -1 && Board[j - 2][i + 2] == -1) {

				printf("ÈÄ°ø ½Â¸®");

				return 1;
			}
		}
	}
	return 0;
}