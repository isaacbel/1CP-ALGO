Program P_S_Cercle ;

Uses Crt;
Var
  P, S, r : Real;
Begin
  Clrscr;
  // Clear the screen
  Gotoxy(10, 5) ;
  Write('Ce code calculer le perimetre et la surface du cercle');
	Write('Cliquer sur enter pour continue');
  Readln;
  Writeln('enter le rayon du cercle');
  Readln(r);
  P := Pi*r*2;
  S := r*r*Pi;
  Writeln('Le perimeter du cercle est : ',P:6:2);
  Writeln;
  Writeln('La surface du cercle est : ',S:6:2);
  Readln;
End.
