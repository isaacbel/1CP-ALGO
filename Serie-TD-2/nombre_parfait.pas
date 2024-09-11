Program NombresParfaits;
Var
  N, i, j, sommeDiviseurs: Integer;
Begin
  Write('Entrez la valeur de N : ');
  Readln(N);
  Writeln('Les nombres parfaits entre 1 et ', N, ' sont : ');
  i := 2;
  While i <= N Do
    // Boucle principale, parcourt les nombres de 2 à N
    Begin
      sommeDiviseurs := 1;
      // Initialise la somme des diviseurs à 1 (pour prendre en compte 1)
      j := 2;
      While j <= (i Div 2) Do
        // Boucle pour trouver les diviseurs de i
        Begin
          If i Mod j = 0 Then
            sommeDiviseurs := sommeDiviseurs + j;
          j := j + 1;
        End;
      If sommeDiviseurs = i Then // Si la somme des diviseurs est égale à i, alors i est parfait
        Writeln(i);
      // Affiche le nombre parfait
      i := i + 1;
    End;
  Readln;
End.
// Fin du programme