Program Exo7 ;
Uses Crt;
Var
  N , p, A , A2, B , C ,D ,N_swap,i,j: Integer;
  Reponse: Char;
  // Variable pour stocker la réponse de l'utilisateur
Begin
  Repeat
    Writeln('enter le nombre N : ');
    Readln(N);
    p := 1 ;
    D := N ;
    A := D Mod 10 ;
    A2 := A;
    i := 0;
    While D <> 0 Do
      // calculer le nombre de positions
      Begin
        D := D Div 10 ;
        i := i+1;
      End;
    For j:=1 To i-1 Do
      Begin
        A := A * 10 ;
        p := p*10;
      End;
    B := (N Mod p) - A2 ;
    C := (N Div p);
    N_swap := A + C + B ;
    Writeln('the swaping numbre is : ',N_swap);
    Writeln('Voulez-vous répéter ? (O/N)');
    Readln(Reponse);
    If Upcase(Reponse) <> 'O' Then // Si la réponse n'est pas 'O' (peu importe la casse)
      Break;
    // Sortir de la boucle si la réponse n'est pas 'O'
    Clrscr;
    // Effacer l'écran
  Until False;
  // Boucler indéfiniment (jusqu'à ce que l'utilisateur choisisse de quitter)
End.
