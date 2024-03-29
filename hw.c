#include <stdio.h>
#include <string.h>

void caesarcipher();
void vigenerecipher_encryption();
void autokeycipher_encryption();
void railfencecipher_encryption();
void rowtranspositionciphers_encryption();

void monoalphabeticcipher_encryption();
void monoalphabeticcipher_decryption();

void vigenerecipher_decryption();
void autokeycipher_decryption();
void railfencecipher_decryption();
void rowtranspositionciphers_decryption();

int main(){
	int i;
	printf("請先將愈加密之文件複製複製到 plaintext.txt \n");
	printf("使用Mono Alphabetic Cipher請將密碼表複製到 table.txt \n");
	printf("------------------------------------\n\n");
	
	while(1){
		printf("請選擇 加密/解密 方法 \n");
		printf("Caesar Cipher (encryption / decryption)....請輸入1 \n");
		printf("Mono Alphabetic Cipher (encryption)........請輸入2 \n");
		printf("Mono Alphabetic Cipher (decryption)........請輸入3 \n");
		printf("Vigenere Cipher (encryption)...............請輸入4 \n");
		printf("Vigenere Cipher (decryption)...............請輸入5 \n");
		printf("Autokey Cipher (encryption)................請輸入6 \n");
		printf("Autokey Cipher (decryption)................請輸入7 \n");
		printf("Rail Fence Cipher (encryption).............請輸入8 \n");
		printf("Rail Fence Cipher (decryption).............請輸入9 \n");
		printf("Row Transposition Ciphers (encryption).....請輸入10 \n");
		printf("Row Transposition Ciphers (decryption).....請輸入11 \n");
		printf("離開.......................................請輸入0 \n");	
		scanf("%d",&i);
		printf("------------------------------------\n\n");
		if(i==1){
			caesarcipher();
		}else if(i==2){
			monoalphabeticcipher_encryption();
		}else if(i==3){
			monoalphabeticcipher_decryption();
		}else if(i==4){
			vigenerecipher_encryption();
		}else if(i==5){
			vigenerecipher_decryption();
		}else if(i==6){
			autokeycipher_encryption();
		}else if(i==7){
			autokeycipher_decryption();
		}else if(i==8){
			railfencecipher_encryption();
		}else if(i==9){
			railfencecipher_decryption();
		}else if(i==10){
			rowtranspositionciphers_encryption();
		}else if(i==11){
			rowtranspositionciphers_decryption();
		}else{
			break;
		}
	}	
	
}

void caesarcipher(){
	int k;
	printf("請輸入向右偏移量:");
	scanf("%d",&k);
	
	FILE *f1,*f2;
	f1=fopen("plaintext.txt","r");
	f2=fopen("ciphertext_caesarcipher.txt","w");
	
	char d,temp;
	while((d=fgetc(f1))!=EOF){                     /*讀取f1內的明文*/ 
		
		if((65<=d && d<=90)||(97<=d && d<=122)){   /*利用ASCII找出大小寫的A~Z*/ 
			if(97<=d && d<=122){
				d=d-32;
			}       							   /*將小寫變成大寫*/ 
			temp=d+k;
			if(temp>90){
				temp=temp-26;
			}       							   /*字母加上偏移量K*/ 
			if(temp<65){
				temp=temp+26;
			}
		}else{
			continue;
		}		
		fprintf(f2,"%c",temp);	     	  	  	   /*將加密好的密文寫進f2裡面並印出來*/ 
	}
	
	fclose(f1);
	fclose(f2);
	printf("finish!\n\n------------------------------------\n");
}

void vigenerecipher_encryption(){
	int len,i=0;
	char k[100];
	
	printf("請輸入keyword (小寫) :"); 
	scanf("%s",&k);
	len=strlen(k);
	
	FILE *f1,*f2;
	f1=fopen("plaintext.txt","r");
	f2=fopen("ciphertext_vigenerecipher.txt","w");
	
	char d,temp;
	while((d=fgetc(f1))!=EOF){	
		
		if((65<=d && d<=90)||(97<=d && d<=122)){
			if(97<=d && d<=122){
				d=d-32;
			}			
			temp=d-'a'+k[i%len];
			if(temp>90){
				temp=temp-26;
			}
			fprintf(f2,"%c",temp);	
			i++;
		}else{
			continue;
		}			
	}
	
	fclose(f1);
	fclose(f2);
	printf("finish!\n\n------------------------------------\n");
}

void autokeycipher_encryption(){
	int len,i=0,flag=0;
	char k[100],t[100];
	
	printf("請輸入keyword (小寫) :");
	scanf("%s",&k);
	len=strlen(k);
	
	FILE *f1,*f2;
	f1=fopen("plaintext.txt","r");
	f2=fopen("ciphertext_autokeycipher.txt","w");
	
	char d,temp;
	while((d=fgetc(f1))!=EOF){		
		
		if((65<=d && d<=90)||(97<=d && d<=122)){			
			if(97<=d && d<=122){
				d=d-32;
			}	
			if(flag==0){
				temp=d+k[i]-'a';
				if(i==len-1){
					flag=1;
				}
			}else{			
				temp=d+t[(i-len)%100]-'A';				
			}
			if(temp>90){
				temp=temp-26;
			}		
			fprintf(f2,"%c",temp);
			t[i%100]=d;
			i++;
		}else{
			continue;
		}			
	}
	
	fclose(f1);
	fclose(f2);
	printf("finish!\n\n------------------------------------\n");
}

void railfencecipher_encryption(){
	int i=0,n=0;
	char t1[999999],t2[999999];

	FILE *f1,*f2;
	f1=fopen("plaintext.txt","r");
	f2=fopen("ciphertext_railfencecipher.txt","w");
	
	char d;
	while((d=fgetc(f1))!=EOF){		

		if((65<=d && d<=90)||(97<=d && d<=122)){			
			if(97<=d && d<=122){
				d=d-32;
			}
				
			if(i%2==0){
				t1[n]=d;
			}else{
				t2[n]=d;
				n++;
			}		
				
			i++;
		}else{
			continue;
		}			
	}
	
	fprintf(f2,"%s",t1);
	fprintf(f2,"%s",t2);
	
	fclose(f1);
	fclose(f2);
	printf("finish!\n\n------------------------------------\n");
}

void rowtranspositionciphers_encryption(){
	int i,j,k,n=0;
	char key[7],d,data[999999]={0};
	char s[7]={'1','2','3','4','5','6','7'};
	printf("請輸入排列順序(1~7 ex:3421567):");
	scanf("%s",&key);
	
	FILE *f1,*f2;
	f1=fopen("plaintext.txt","r");
	f2=fopen("ciphertext_rowtranspositionciphers.txt","w");
	
	while((d=fgetc(f1))!=EOF){		
		
		if((65<=d && d<=90)||(97<=d && d<=122)){			
			if(97<=d && d<=122){
				d=d-32;
			}		
		data[n]=d;
		n++;			
		}else{
			continue;
		}			
	}
	
	for(i=0;i<7;i++){
		for(j=0;j<7;j++){
			if(key[i]==s[j]){
				for(k=0;k<n;k++){
					if(k%7==j){
						fprintf(f2,"%c",data[k]);
					}
				}
				break;
			}
		}
	}
	
	fclose(f1);
	fclose(f2);
	printf("finish!\n\n------------------------------------\n");	
}

void monoalphabeticcipher_encryption(){
	
}

void monoalphabeticcipher_decryption(){
	
}

void vigenerecipher_decryption(){
	
}

void autokeycipher_decryption(){
	
}

void railfencecipher_decryption(){
	
}

void rowtranspositionciphers_decryption(){
	
}
