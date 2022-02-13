#define  GOODDIVISION(X,Y) (X % Y == 0 ? X / Y : X / Y + 1)
void
tatami(Monitor *m) {
	unsigned int i, n, nx, ny, nw, nh, mats, tc, tnx, tny, tnw, tnh;
	Client *c;

	for(n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), ++n);

	if (n == 0)
		return;
	nx = m->wx;
	ny = 0;
	nw = m->ww;
	nh = m->wh - TATAMIGAPPX;
	c = nexttiled(m->clients);
	if (n != 1)
		nw = m->ww * m->mfact;
	ny = m->wy;
	/* first client */
	resize(c, nx + TATAMIGAPPX, ny + TATAMIGAPPX, nw - (2 * c->bw) - (2 * TATAMIGAPPX), nh - (2 * c->bw) - TATAMIGAPPX, False);
	if (n <= 1)
		return;
	c = nexttiled(c->next);
	nx += nw;
	nw = m->ww - nw;
	tc = n - 1;
	mats = tc / 5;
	nh /= (mats + (tc % 5 > 0));

	for(i = 0; c && (i < (tc % 5)); c = nexttiled(c->next)) {
		tnw = nw;
		tnx = nx;
		tnh = nh;
		tny = ny + TATAMIGAPPX;
		switch (tc - (mats * 5)) {
		case 1: /* fill */
			break;
		case 2: /* up and down */
			if ((i % 5) == 0) { /* up */
				tnh = GOODDIVISION(tnh, 2);
			} else if ((i % 5) == 1) { /* down */
				tnh = GOODDIVISION(tnh, 2);
				tny += nh / 2;
			}
			break;
		case 3: /* bottom, up-left and up-right */
			if ((i % 5) == 0) { /* up-left */
				tnw = nw / 2;
				tnh = GOODDIVISION(2 * nh, 3);
			} else if ((i % 5) == 1) { /* up-right */
				tnx += nw / 2;
				tnw = nw / 2;
				tnh = GOODDIVISION(2 * nh, 3);
			} else if ((i % 5) == 2) { /* bottom */
				tnh = GOODDIVISION(nh, 3);
				tny += (2 * nh) / 3;
			}
			break;
		case 4: /* bottom, left, right and top */
			if ((i % 5) == 0) { /* top */
				tnh = GOODDIVISION(nh, 4);
			} else if ((i % 5) == 1) { /* left */
				tnw = nw / 2;
				tny += nh / 4;
				tnh = GOODDIVISION(nh, 2);
			} else if ((i % 5) == 2) { /* right */
				tnx += nw / 2;
				tnw = nw / 2;
				tny += nh / 4;
				tnh = GOODDIVISION(nh, 2);
			} else if ((i % 5) == 3) { /* bottom */
				tny += (3 * nh) / 4;
				tnh = GOODDIVISION(nh, 4);
			}
			break;
		}
		tnw -= TATAMIGAPPX;
		tnh -= TATAMIGAPPX;
		i++;
		resize(c, tnx, tny, tnw - 2 * c->bw, tnh - 2 * c->bw, False);
	}
	++mats;
	for(i = 0; c && (mats > 0); c = nexttiled(c->next)) {
		if ((i % 5) == 0) {
			--mats;
			if (((tc % 5) > 0) || (i >= 5))
				ny += nh;
		}
		tnw = nw;
		tnx = nx;
		tnh = nh;
		tny = ny + TATAMIGAPPX;

		switch(i % 5) {
		case 0: /* top-left-vert */
			tnw = nw / 3;
			tnh = GOODDIVISION(nh * 2, 3);
			break;
		case 1: /* top-right-hor */
			tnx += nw / 3;
			tnw = (nw * 2) / 3;
			tnh = GOODDIVISION(nh, 3);
			break;
		case 2: /* center */
			tnx += nw / 3;
			tnw = nw / 3;
			tny += nh / 3;
			tnh = GOODDIVISION(nh, 3);
			break;
		case 3: /* bottom-right-vert */
			tnx += (nw * 2) / 3;
			tnw = nw / 3;
			tny += nh / 3;
			tnh = GOODDIVISION(nh * 2, 3);
			break;
		case 4: /* (oldest) bottom-left-hor */
			tnw = (2 * nw) / 3;
			tny += (2 * nh) / 3;
			tnh = GOODDIVISION(nh, 3);
			break;
		default:
			break;
		}
		tnw -= TATAMIGAPPX;
		tnh -= TATAMIGAPPX;
		i++;
		/* i %= 5; */
		resize(c, tnx, tny, tnw - 2 * c->bw, (tnh) - 2 * c->bw, False);
	}
}
