
%/teamspace/studios/this_studio/test.cœ#include <stdio.h>

typedef struct {
    int squareFeet;
    int numberOfBedrooms;
    int numberOfBathrooms;
} House;

void vecAdd(float *a, float *b, float *c, int n) {
    for (int i = 0; i < 3; i++) {
        c[i] = a[i]+b[i];
    }
}

void addMatrix(float *a, float *b, float *c, int n, int l) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            // *(c+i*l+j) = *(a+i*l+j) + *(b+i*l+j);
            c[i*l+j] = a[i*l+j] + b[i*l+j];
            
        }
    }
}

void printMatrix(float *a, int n, int l) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            printf("%f ", *(a+i*l+j));
        }
        printf("\n");
    }
}

void printVec(float *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%f\n", a[i]);
    }
}


void main() {
    printf("Hello, World!\n");
    int *x,y;
    y=15;
    printf("%d\n", y);
    x = &y;
    *x = 10;
    printf("%d\n", y);

    House someHouse = {960,2,1};

    printf("squareFeet: %d\n", someHouse.squareFeet);
    printf("numberOfBedrooms: %d\n", someHouse.numberOfBedrooms);
    printf("numberOfBathrooms: %d\n", someHouse.numberOfBathrooms);

    House *myHouse;
    myHouse = &someHouse;
    printf("squareFeet: %d\n", myHouse->squareFeet);
    printf("numberOfBedrooms: %d\n", myHouse->numberOfBedrooms);
    printf("numberOfBathrooms: %d\n", myHouse->numberOfBathrooms);

    char someString[] = "Hello, World!";
    printf("%c\n", someString[1]);
    char *pString = someString;
    printf("%c\n", *(pString+9));
    printf("%c\n", someString[1]);
    printf("%p\n",(void*)someString[1]);
    printf("%p\n",(void*)pString);

    int aNums[] = {1,2,3,4,5};
    // printf("%d\n", aNums);
    int *pNums = &aNums;
    
    pNums++;
    printf("%d\n", *pNums);

    printf("%p\n", (void*)pNums);

    float a[3] = {1,2,3};
    float b[3] = {4,5,6};
    float c[3];
    vecAdd(a,b,c,3);
    printf("%f\n", c[0]);
    printf("%f\n", c[1]);
    printf("%f\n", c[2]);
    printf("\n");
    printVec(c,3);

    float mat[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    printMatrix(mat,3,3);
    printf("\n");
    float mat2[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    float mat3[3][3];
    addMatrix(mat,mat2,mat3,3,3);
    printMatrix(mat3,3,3);

}  2) *$5a99a4bb-1915-45a9-bd5d-be920eccdb1508)8289 *$5a99a4bb-1915-45a9-bd5d-be920eccdb15089@ 0@R*$40f96083-4efa-49ab-9c54-8c2d35993eed08RS 0Sw*$8065d24f-7995-4e21-a35a-fcf03482098508	wâ 2â†*$d4088a96-e69f-4786-b3f0-2a712ee8576708
†® 
®Ø Ø≥
≥’ 
’Ê 
ÊÓ 
Ó˛ 4˛¢ *$23bc314e-d112-44bf-a0dc-dff2dd7d382008
¢© 4©¨ *$23bc314e-d112-44bf-a0dc-dff2dd7d382008
¨≠ 4≠Î *$74e23ded-6318-43c0-87af-56fe64547ef208ÎÏ4Ïı *$74e23ded-6318-43c0-87af-56fe64547ef2084ıÅ *$91cc1e92-9391-4b51-9db2-54f8bd74b56f08ÅÑ
Ñé 2é©*$9c30631d-0735-4fd4-9389-719d0ea338f708©∂
∂∫ 2∫Ω*$8cfc974c-0928-4886-9809-27280fb2d06808
Ωæ 2æ’*$8cfc974c-0928-4886-9809-27280fb2d068084’ﬁ *$91cc1e92-9391-4b51-9db2-54f8bd74b56f08
ﬁÎ 4Îı *$91cc1e92-9391-4b51-9db2-54f8bd74b56f08
ıÄ 4Ä• *$12492dda-37a8-4221-8c52-3236a8924d9f082•¬*$545b2c31-402b-49dd-886d-101c157120ef084¬√ *$12492dda-37a8-4221-8c52-3236a8924d9f082√∂*$545b2c31-402b-49dd-886d-101c157120ef084∂∑ *$12492dda-37a8-4221-8c52-3236a8924d9f08
∑∆ 2∆Ÿ*$900a074d-7940-4f9a-8b64-526a1b3befde08
Ÿ⁄ 4⁄¢ *$95334e4f-8e15-4442-9fd2-77926bd4d85808
¢® 
®— 
—Ì 
Ì˜ ˜˘
˘ˇ 
ˇÑ 2Ñã*$dd2496c1-54fa-4cd4-8cba-7d895a5b009b08
ãê 2êò*$c5cf1660-6480-43be-9c3b-e17d5448861108
òô 4ôß *$ecec47b1-4438-4e4a-b868-8d9cfdd4205908ß©4©¨ *$ecec47b1-4438-4e4a-b868-8d9cfdd4205908¨≠4≠∞ *$ecec47b1-4438-4e4a-b868-8d9cfdd4205908
∞ø 
ø◊ 
◊ﬁ 2ﬁÜ*$e67c2a68-9140-4d65-bab3-74732a64403d08
Üá 2áà*$e67c2a68-9140-4d65-bab3-74732a64403d08
àì 2ì *$78bdc7bd-c446-4cb8-8e0e-52f30844019c08
 À 2Àè	*$78bdc7bd-c446-4cb8-8e0e-52f30844019c08
è	ô	 4ô	¢	 *$cc20a8ca-e047-429d-b48e-1187b146492508
¢	§	 4§	®	 *$cc20a8ca-e047-429d-b48e-1187b146492508
®	Ø	 2Ø	Ω	*$7fe35ecc-2bcd-4dd7-86e4-6faa04b703ab08
Ω	¬	 4¬	˜
 *$cc20a8ca-e047-429d-b48e-1187b146492508
˜
Ö 2Ö†*$a404a97d-4b70-4fc0-951d-39fc55321b4508
†™ ™´
´≠ 4≠Æ *$1fa0325d-c8fa-4efa-9b75-ca2d92051c4408ÆØ4Ø¥ *$1fa0325d-c8fa-4efa-9b75-ca2d92051c4408
¥« 
«» 
»’ 2’„*$4a5ce6a2-5925-4433-b65e-0611cab49cc008
„‰ 4‰Ò *$280235b9-5dd7-42af-9114-fb90d864c3a008ÒÚ4Ú˜ *$280235b9-5dd7-42af-9114-fb90d864c3a008˜˘4˘Ä *$280235b9-5dd7-42af-9114-fb90d864c3a008
ÄÇ 4ÇÉ *$280235b9-5dd7-42af-9114-fb90d864c3a008ÉÑ4ÑÜ *$280235b9-5dd7-42af-9114-fb90d864c3a0084Üì *$9fb25d80-ce30-4cc9-8115-f51a737817c408ìî4î£ *$9fb25d80-ce30-4cc9-8115-f51a737817c408
£¶ 4¶© *$9fb25d80-ce30-4cc9-8115-f51a737817c408
©¬ 2¬Ã*$1146cca4-a1d5-45d2-bb42-16a6d51d908d08
Ã– 2–—*$1146cca4-a1d5-45d2-bb42-16a6d51d908d08
—“ 4“ı *$c6b92678-ce3b-450a-8e9b-5fbb1468e6b508
ıâ 2âí*$c3f2591b-92ee-4db4-8534-8f46445bc4fe08
íì 4ìô *$c3f2591b-92ee-4db4-8534-8f46445bc4fe08
ô¢ 4¢≤ *$8d97e07c-7b0a-4774-a53e-4ef469bf974f08
≤‚ 2‚˘*$47159a12-027b-489c-ab47-d8dabf63c1f508
˘¢ 2¢∑*$6b34ea6c-8d0c-4e37-bd5b-205b64fc8dc308
∑∏ 2∏≈*$e952549c-5738-4738-811f-cd7b6b4f7c1208
≈÷ 2÷◊*$2226573a-ab8d-4206-b54c-39c42611eb2308
◊€ 4€‰ *$2226573a-ab8d-4206-b54c-39c42611eb2308‰Â4ÂÈ *$2226573a-ab8d-4206-b54c-39c42611eb2308
ÈÔ 2Ôõ*$fb0c0c51-2743-49c7-aa7a-4d951563b90b08
õú 2ú≤*$4356b8d0-b48c-4652-9fc6-3ac5c7c8adba082≤Õ*$51683516-4927-44c4-8122-7941f7a86b8808
ÕŒ 
Œœ 2,file:///teamspace/studios/this_studio/test.c