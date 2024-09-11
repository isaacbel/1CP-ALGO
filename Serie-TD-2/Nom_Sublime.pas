Program Nom_Sublime;
Var
  N1, N2, Num, P, S, L, i, k, j, u: Longint;
  // Déclaration des variables
Begin
  Writeln('Entre l''intervalle : ');
  // Demande à l'utilisateur d'entrer l'intervalle
  Readln(N1, N2);
  // Lit les valeurs de l'intervalle
  For Num := N1 To N2 Do
    // Parcourt les nombres de N1 à N2
    Begin
      i := 0;
      P := 0;
      S := 0;
      L := 0;
      u := 1 ;
      While (u <= Num) Do
        // Boucle pour calculer la somme et le nombre de diviseurs
        Begin
          If (Num Mod u = 0) Then
            Begin
              P := P + u;
              i := i + 1;
            End;
          u := u + 1;
        End;
      For j := 1 To (P Div 2) Do
        // Boucle pour calculer la somme des diviseurs de P
        Begin
          If (P Mod j = 0) Then
            Begin
              S := S + j;
            End;
        End;
      For k := 1 To (i Div 2) Do
        // Boucle pour calculer le nombre de diviseurs de i
        Begin
          If (i Mod k = 0) Then
            Begin
              L := L + k;
            End;
        End;
      If (S = P) And (L = i) Then // Vérifie si S et L sont des nombres parfaits
        Begin
          Writeln(Num);
          // Affiche le nombre sublime
        End;
    End;
  Readln;
  // Attente de l'appui sur une touche pour fermer la console
End.