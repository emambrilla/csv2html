SOURCE=./source
HDRS=./hdrs

all: $(MYTARGET)/csv2html

clean:
	@echo Borrando...
	@$(MYRM) $(MYTARGET)/csv2html$(MYEXE_SUFFIX)

$(MYTARGET)/csv2html: $(SOURCE)/csv2html.c
	@echo Compilando csv2html
	@$(MYCC) $(SOURCE)/csv2html.c -o $(MYTARGET)/csv2html
