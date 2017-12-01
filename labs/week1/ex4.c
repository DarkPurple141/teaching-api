// S1                                      // S2
switch (ch) {                              switch (ch) {
    case 'a':  printf("eh? "); break;          case 'a':  printf("eh? ");
    case 'e':  printf("eee "); break;          case 'e':  printf("eee ");
    case 'i':  printf("eye "); break;          case 'i':  printf("eye ");
    case 'o':  printf("ohh "); break;          case 'o':  printf("ohh ");
    case 'u':  printf("you "); break;          case 'u':  printf("you ");
}                                          }
printf("\n");                              printf("\n");


switch (ch) {
   case 'a':
   case 'e':
   case 'i':
   case 'o':
   case 'u':
      processVowel(ch);
      break;
   default:
      errorCase(ch);
}
