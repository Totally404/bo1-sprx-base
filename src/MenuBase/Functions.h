void constRun() {

	if (options.grid) {
		for (float x = 0; x < 1; x+= 0.1) {
			drawShader(x, 0, 0.001, 1, White);
		}
		for (float y = 0; y < 1; y += 0.1) {
			drawShader(0, y, 1, 0.001, White);
		}
		
		for (float x = 0; x < 1; x += 0.025) {
			drawShader(x, 0, 0.001, 1, LightWhite);
		}
		for (float y = 0; y < 1; y += 0.025) {
			drawShader(0, y, 1, 0.001, LightWhite);
		}
	}

	if (options.fov != 65) {
		char buf1[64] = "cg_fov ";
		char buf2[64];
		ftoa(options.fov, buf2, 2);
		//strcpy(buf1, one);
		strcat(buf1, buf2);
		cBuf_Addtext(0, buf1);
	}
}

//gets value from memory rather than a variable so it is always updated, even after changing in an rtm
bool redBoxesBool() {;
	return *(char*)0x1205C0 == 0x60;
}

void toggleRedBoxes() {
	if (redBoxesBool()) {
		unsigned char bytes[4] = { 0x41, 0x86, 0x02, 0x78 };
		write_process(0x1205C0, &bytes, 4);
	}
	else {
		unsigned char bytes[4] = { 0x60, 0x00, 0x00, 0x00 };
		write_process(0x1205C0, &bytes, 4);
	}
}

//Designer
void toggleGrid() { options.grid = !options.grid; }

void openKeyboard(void(*f)(char*)) {
	keyboardOpened = true;
	keyboardFunction = f;
}
void setName(char* name) {
	strcpy((char*)0x02000934, name);
}
void openNameKeyboard() {
	openKeyboard(setName);
}
