#include <stdio.h>
#include <string.h>
int main() {
	char *text = "#include <stdio.h>\n\
#include <string.h>\n\
int main() {\n\
	char *text = \"?\";\n\
	for (int i = 0; i < strlen(text); i++) {\n\
		if (text[i] == (char) 63) {\n\
			for (int j = 0; j < strlen(text); j++) {\n\
				if (text[j] == '\"') {\n\
					printf(\"%c%c\", (char) 92, (char) 34);\n\
				} else if (text[j] == 0x0A) {\n\
					printf(\"%c%c%c%c\", 92, 110, 92, 0x0A); \n\
				} else {\n\
					printf(\"%c\", text[j]);\n\
				}\n\
			}\n\
		} else {\n\
			printf(\"%c\", text[i]);\n\
		}\n\
	}\n\
}\n\
";
	for (int i = 0; i < strlen(text); i++) {
		if (text[i] == (char) 63) {
			for (int j = 0; j < strlen(text); j++) {
				if (text[j] == '"') {
					printf("%c%c", (char) 92, (char) 34);
				} else if (text[j] == 0x0A) {
					printf("%c%c%c%c", 92, 110, 92, 0x0A); 
				} else {
					printf("%c", text[j]);
				}
			}
		} else {
			printf("%c", text[i]);
		}
	}
}
