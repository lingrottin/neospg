build: main.c locales/zh_CN.po
	-mkdir -p out/locale
	cc main.c -o out/neospg
	msgfmt locales/zh_CN.po -o out/locale/zh_CN.mo

build_locale: locales/zh_CN.po
	-mkdir -p out/locale
	msgfmt zh_CN.po -o out/locale/zh_CN.mo

build_c:
	-mkdir -p out
	cc main.c -o out/neospg
install:
	cp out/neospg /usr/bin
	chmod +x /usr/bin/neospg
	cp out/locale/zh_CN.mo /usr/share/locale/zh_CN/LC_MESSAGES/neospg.mo
clean:
	-rm -r out