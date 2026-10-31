# Headless mGBA smoke-test harness. Needs libmgba-dev
# (Debian/Ubuntu: sudo apt-get install libmgba-dev).
smoke: smoke.c
	$(CC) -O2 -o $@ $< -lmgba

clean:
	rm -f smoke
