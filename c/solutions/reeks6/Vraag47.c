
void wijzig_eerste_cijfer(int *g) { 
      int hulp = *g; 
      int f = 0xf; 
      hulp >>= 4; 
      while (hulp) { 
            f <<= 4; 
            hulp >>= 4; 
      }
      *g |= f; 
}

