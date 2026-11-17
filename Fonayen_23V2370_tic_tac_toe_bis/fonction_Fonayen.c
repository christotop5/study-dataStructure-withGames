#include "fonction_Fonayen.h"

void Init_actual_stateFO(post actual_stateFO[]){
	for(int i=0;i<10;i++){
		actual_stateFO[i].x = -1*(i);
		actual_stateFO[i].y = -1*(i+9);
	}
}

void Init_stateFO(int stateFO[]){
	for(int i=0;i<10;i++){
		stateFO[i] = -1;
	}
}

void Init_BordFO(plateau TabFO){
	for(int i = 0;i <= 12;i++){
		for(int j=0;j <= 15;j++){
			TabFO[i][j]=' ';
		}
	}


	for(int i = 0;i <= 12;i++){
		for(int j=0;j <= 15;j++){
			if( j==0 || i==0 || i==12 || j==15  || i== 4 || j==5||i==8||j==10) TabFO[i][j] ='#';
		}
	}
}

void Drow_BordFO(plateau TabFO){
	for(int i = 0;i <= 12;i++){
		for(int j=0;j <= 15;j++){
			printf("%c",TabFO[i][j]);
		}
		printf("\n");
	}

}

int Drow_xFO(plateau TabFO,int position,int i,post actual_stateFO[],char* name){
	printf("\n\nit here\n\n");
	if(position == 1){
		TabFO[2][2] = name[0];
		TabFO[2][3] = name[1];
		actual_stateFO[i].x = 1;
		actual_stateFO[i].y = 1;
		return 1;
	}else if(position == 2){
		TabFO[2][8] = name[0];
		TabFO[2][9] = name[1];
		actual_stateFO[i].x = 1;
		actual_stateFO[i].y = 2;
		return 2;
	}else if(position == 3){
		TabFO[2][13] = name[0];
		TabFO[2][14] = name[1];
		actual_stateFO[i].x = 1;
		actual_stateFO[i].y = 3;
		return 3;	
	}else if(position == 4){
		TabFO[6][2] = name[0];
		TabFO[6][3] = name[1];
		actual_stateFO[i].x = 2;
		actual_stateFO[i].y = 1;
		return 4;
	}else if(position == 5){
		TabFO[6][8] = name[0];
		TabFO[6][9] = name[1];
		actual_stateFO[i].x = 2;
		actual_stateFO[i].y = 2;
		return 5;
	}else if(position == 6){
		TabFO[6][13] = name[0];
		TabFO[6][14] = name[1];
		actual_stateFO[i].x = 2;
		actual_stateFO[i].y = 3;
		return 6;
	}else if(position == 7){
		TabFO[10][2] = name[0];
		TabFO[10][3] = name[2];
		actual_stateFO[i].x = 3;
		actual_stateFO[i].y = 1;
		return 7;
	}else if(position == 8){
		TabFO[10][8] = name[0];
		TabFO[10][9] = name[1];
		actual_stateFO[i].x = 3;
		actual_stateFO[i].y = 2;
		return 8;
	}else if(position == 9){
		TabFO[10][13] = name[0];
		TabFO[10][14] = name[1];
		actual_stateFO[i].x = 3;
		actual_stateFO[i].y = 3;
		return 9;
	}

}

int Drow_oFO(plateau TabFO,int position,int i,post actual_stateFO[],char* name){
	if(position == 1){
		TabFO[2][2] = name[0];
		TabFO[2][3] = name[1];
		actual_stateFO[i].x = 1;
		actual_stateFO[i].y = 1;
		return 1;
	}else if(position == 2){
		TabFO[2][8] = name[0];
		TabFO[2][9] = name[1];
		actual_stateFO[i].x = 1;
		actual_stateFO[i].y = 2;
		return 2;
	}else if(position == 3){
		TabFO[2][13] = name[0];
		TabFO[2][14] = name[1];
		actual_stateFO[i].x = 1;
		actual_stateFO[i].y = 3;
		return 3;
	}else if(position == 4){
		TabFO[6][2] = name[0];
		TabFO[6][3] = name[1];
		actual_stateFO[i].x = 2;
		actual_stateFO[i].y = 1;
		return 4;
	}else if(position == 5){
		TabFO[6][8] = name[0];
		TabFO[6][9] = name[1];
		actual_stateFO[i].x = 2;
		actual_stateFO[i].y = 2;
		return 5;
	}else if(position == 6){
		TabFO[6][13] = name[0];
		TabFO[6][14] = name[1];
		actual_stateFO[i].x = 2;
		actual_stateFO[i].y = 3;
		return 6;
	}else if(position == 7){
		TabFO[10][2] = name[0];
		TabFO[10][3] = name[1];
		actual_stateFO[i].x = 3;
		actual_stateFO[i].y = 1;
		return 7;
	}else if(position == 8){
		TabFO[10][8] = name[0];
		TabFO[10][9] = name[1];
		actual_stateFO[i].x = 3;
		actual_stateFO[i].y = 2;
		return 8;
	}else if(position == 9){
		TabFO[10][13] = name[0];
		TabFO[10][14] = name[1];
		actual_stateFO[i].x = 3;
		actual_stateFO[i].y = 3;
		return 9;
	}
}

int is_evenFO(int n){
	return n%2 == 0;
}

int in_stateFO(int stateFO[9],int n ){
	for(int i=0;i<9;i++){
		if(stateFO[i]==n) return 1;
	}
	return 0;
}

int has_wornFO(int stateFO[9],int i,post actual_stateFO[]){
	int count=0;
	if(is_evenFO(i)){
		if(i==4){
			if(actual_stateFO[0].x == actual_stateFO[2].x  && actual_stateFO[2].x == actual_stateFO[4].x) return 1;
			if(actual_stateFO[0].y == actual_stateFO[2].y  && actual_stateFO[2].y == actual_stateFO[4].y) return 1;
			for(int p=0;p<=4;p +=2 ){
				if(actual_stateFO[p].x == actual_stateFO[p].y) count++;
			}if(count == 3) return 1;
			count=0;
			for(int l=0;l<=4;l +=2 ){
				if(actual_stateFO[l].x == 4 - actual_stateFO[l].y) count++;
				printf("\n\t\t%d\n",count);
			}return count == 3;
		}else if(i==6){
			if(actual_stateFO[6].x == actual_stateFO[0].x  && actual_stateFO[0].x == actual_stateFO[2].x) return 1;
			if(actual_stateFO[6].x == actual_stateFO[0].x  && actual_stateFO[0].x == actual_stateFO[4].x) return 1;
			if(actual_stateFO[6].x == actual_stateFO[2].x  && actual_stateFO[2].x == actual_stateFO[4].x) return 1;
			if(actual_stateFO[6].y == actual_stateFO[0].y  && actual_stateFO[0].y == actual_stateFO[2].y) return 1;
			if(actual_stateFO[6].y == actual_stateFO[0].y  && actual_stateFO[0].y == actual_stateFO[4].y) return 1;
			if(actual_stateFO[6].y == actual_stateFO[2].y  && actual_stateFO[2].y == actual_stateFO[4].y) return 1;
			for(int p=2;p<=6;p +=2 ){
				if(actual_stateFO[p].x == actual_stateFO[p].y) count++;
			}if(count == 3) return 1;
			count=0;
			for(int p=0;p<=6;p +=2 ){
				if(actual_stateFO[p].x == actual_stateFO[p].y && p!=2) count++;
			}if(count == 3) return 1;
			count=0;
			for(int p=0;p<=6;p +=2 ){
				if(actual_stateFO[p].x == actual_stateFO[p].y && p!=4) count++;
			}if(count == 3) return 1;
			count=0;
			for(int l=0;l<=4;l +=2 ){
				if(actual_stateFO[l].x == 4 - actual_stateFO[l].y) count++;
				printf("\n\t\t%d\n",count);
			}if(count == 3) return 1;
			count=0;
			for(int l=0;l<=6;l +=2 ){
				if(actual_stateFO[l].x == 4 - actual_stateFO[l].y && l!=2) count++;
				printf("\n\t\t%d\n",count);
			}if(count == 3) return 1;
			count=0;
			for(int l=0;l<=6;l +=2 ){
				if(actual_stateFO[l].x == 4 - actual_stateFO[l].y && l!=4) count++;
				printf("\n\t\t%d\n",count);
			}if(count == 3) return 1;
		}
		
	}else {
		if(i==5){
			if(actual_stateFO[1].x == actual_stateFO[3].x  && actual_stateFO[3].x == actual_stateFO[5].x) return 1;
			if(actual_stateFO[1].y == actual_stateFO[3].y  && actual_stateFO[3].y == actual_stateFO[5].y) return 1;
			for(int p=1;p<=5;p +=2 ){
				if(actual_stateFO[p].x == actual_stateFO[p].y) count++;
			}if(count == 3) return 1;
			count = 0;
			for(int l=1;l<=5;l +=2 ){
				if(actual_stateFO[l].x ==  4- actual_stateFO[l].y) count++;
			}return count == 3;
		}else if(i==7){
			if(actual_stateFO[7].x == actual_stateFO[1].x  && actual_stateFO[1].x == actual_stateFO[3].x) return 1;
			if(actual_stateFO[7].x == actual_stateFO[1].x  && actual_stateFO[1].x == actual_stateFO[5].x) return 1;
			if(actual_stateFO[7].x == actual_stateFO[3].x  && actual_stateFO[3].x == actual_stateFO[5].x) return 1;
			if(actual_stateFO[7].y == actual_stateFO[1].y  && actual_stateFO[1].y == actual_stateFO[3].y) return 1;
			if(actual_stateFO[7].y == actual_stateFO[1].y  && actual_stateFO[1].y == actual_stateFO[5].y) return 1;
			if(actual_stateFO[7].y == actual_stateFO[3].y  && actual_stateFO[3].y == actual_stateFO[5].y) return 1;
			for(int p=3;p<=7;p +=2 ){
				if(actual_stateFO[p].x == actual_stateFO[p].y) count++;
			}if(count == 3) return 1;
			count=0;
			for(int p=1;p<=7;p +=2 ){
				if(actual_stateFO[p].x == actual_stateFO[p].y && p!=3) count++;
			}if(count == 3) return 1;
			count=0;
			for(int p=1;p<=7;p +=2 ){
				if(actual_stateFO[p].x == actual_stateFO[p].y && p!=5) count++;
			}if(count == 3) return 1;
			count=0;
			for(int l=3;l<=7;l +=2 ){
				if(actual_stateFO[l].x == 4 - actual_stateFO[l].y) count++;
				printf("\n\t\t%d\n",count);
			}if(count == 3) return 1;
			count=0;
			for(int l=1;l<=7;l +=2 ){
				if(actual_stateFO[l].x == 4 - actual_stateFO[l].y && l!=3) count++;
				printf("\n\t\t%d\n",count);
			}if(count == 3) return 1;
			count=0;
			for(int l=1;l<=7;l +=2 ){
				if(actual_stateFO[l].x == 4 - actual_stateFO[l].y && l!=5) count++;
				printf("\n\t\t%d\n",count);
			}if(count == 3) return 1;
		}
	}

	return 0;
}

void directivesFO(){
	printf("Enter the number for corespoding position **'[1][1] [1][2] [1][3] [2][1] [2][2] [2][3] [3][1] [3][2] [3][3]'** ");
}

int determin(int x,int y){
	if(x==1 && y==1) return 1;
	if(x==1 && y==2) return 2;
	if(x==1 && y==3) return 3;
	if(x==2 && y==1) return 4;
	if(x==2 && y==2) return 5;
	if(x==2 && y==3) return 6;
	if(x==3 && y==1) return 7;
	if(x==3 && y==2) return 8;
	if(x==3 && y==3) return 9;
	else return 0;
}

