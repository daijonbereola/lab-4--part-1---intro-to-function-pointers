#include <stdio.h>
#include <stdlib.h>

typedef int (*Operation) (int a, int b);

int add (int a, int b) { 
  printf ("'a' + 'b' = "); 
  return a + b; 
}

int subtract (int a, int b) { 
  printf ("'b' - 'a' = "); 
  return a - b; 
}

int multiply (int a, int b) { 
  printf ("'a' * 'b' = "); 
  return a * b; 
}

int divide (int a, int b) { 
  printf ("'a' / 'b' = "); 
  return a / b; 
}

int main (void)
{
  // Array of functions of type
	Operation operations[4];
	char operation[10];
  int operation_n;
	
	operations[0] = &add;
	operations[1] = &subtract;
	operations[2] = &multiply;
	operations[3] = &divide;
  
  int a = 6;
  int b = 3;
  int result;
  
  while(1){
    printf("Operand 'a' : %d | Operand 'b' : %d Specify the operation to perform (0 : add | 1 : subtract | 2 : Multiply | 3: divide | 4 : exit):", 
           a, b);
    scanf("%s", operation);
    operation_n = atoi(operation);
    while (operation_n > 4) {
      printf("Specify the operation to perform (0 : add | 1 : subtract | 2 : Multiply | 3: divide | 4 : exit):");
      scanf("%s", operation); 
      operation_n = atoi(operation);
    }
		
		if (operation_n == 4){
			printf("Quit Program.\n");
			break;
		}
		
		// Depending on user input, performs the operation on intergers a and b and prints the result. 
		result = (*operations[operation_n])(a, b);
		printf("%d\n", result);
	}

	return 0;
}
