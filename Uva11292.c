/*
==================================================
    @autor : Heliton Leno  01/06/2017
==================================================
    https://uva.onlinejudge.org
==================================================
    Solução do problema 11292 - Dragon of Loowater
==================================================
*/

int main(){
	int numberHeads = 0;
	int numberknights = 0;
	
	while(scanf("%d %d", &numberHeads, &numberknights)){
		if(numberHeads == 0 && numberknights == 0) break;
		
		int dragon[numberHeads];
		int knights[numberknights];
		
		int i = 0;
		for(; i < numberHeads; i++){
			scanf("%d", &dragon[i]);
		}
		
		i = 0;
		for(; i < numberknights; i++){
			scanf("%d", &knights[i]);
		}
		
		insertionSort(dragon, numberHeads);
		insertionSort(knights, numberknights);
		
		int pay = 0;
        int loser = 0;
        int ok = 1;

        for(i = 0; i < numberHeads; i++){
            if(numberHeads - i > numberknights - pay){
                loser = -1;
                ok = 0;
                break;
            }

			int j = pay;
            for(; j < numberknights; j++){
                if(knights[j] < dragon[i]){
                    pay++;
                    continue;
                }
                loser += knights[j];
                pay++;
                ok = 1;
                break;
            }
        }
        if(loser == -1 && ok == 0)
            printf("Loowater is doomed!\n");
        else
            printf("%d\n", loser);
	
	}
}

int insertionSort(int original[], int length) {
        int i, j, atual;

        for (i = 1; i < length; i++) {
            atual = original[i];
            j = i - 1;

            while ((j >= 0) && (atual < original[j])) {
                original[j + 1] = original[j];
                j = j - 1;
            }

            original[j + 1] = atual;
        }

        return original;
    }