#include <stdio.h>
#include <string.h>
int main() {
	char *text = "#include <stdio.h>\n\
#include <string.h>\n\
int main() {\n\
	char *text = ?;\n\
	const char format_one_chars[] = {'%', 'c', 0};\n\
	const char format_four_chars[] = {'%', 'c', '%', 'c', '%', 'c', '%', 'c', 0};\n\
	for (int i = 0; i < strlen(text); i++) {\n\
		if (text[i] == (char) 63) {\n\
			printf(format_one_chars, 34);\n\
			for (int j = 0; j < strlen(text); j++) {\n\
				if (text[j] == 0x0A) {\n\
					printf(format_four_chars, 92, 110, 92, 0x0A); \n\
				} else {\n\
					printf(format_one_chars, text[j]);\n\
				}\n\
			}\n\
			printf(format_one_chars, 34);\n\
		} else {\n\
			printf(format_one_chars, text[i]);\n\
		}\n\
	}\n\
}\n\
";
	const char format_one_chars[] = {'%', 'c', 0};
	const char format_four_chars[] = {'%', 'c', '%', 'c', '%', 'c', '%', 'c', 0};
	for (int i = 0; i < strlen(text); i++) {
		if (text[i] == (char) 63) {
			printf(format_one_chars, 34);
			for (int j = 0; j < strlen(text); j++) {
				if (text[j] == 0x0A) {
					printf(format_four_chars, 92, 110, 92, 0x0A); 
				} else {
					printf(format_one_chars, text[j]);
				}
			}
			printf(format_one_chars, 34);
		} else {
			printf(format_one_chars, text[i]);
		}
	}
}
