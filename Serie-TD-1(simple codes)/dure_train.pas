Program CalculHeureArrivee ;
Var
  d_seconde, d_minute, d_heure,
  t_seconde, t_minute, t_heure,
  a_seconde, a_minute, a_heure , J : Integer;
Begin
  Writeln('Donner le temps de depart (seconde, minute, heure) :');
  // Étape 1
  Readln(d_seconde, d_minute, d_heure);
  Writeln('Donner la duree du trajet (seconde, minute, heure) :');
  Readln(t_seconde, t_minute, t_heure);
  a_seconde := d_seconde + t_seconde;
  // Étape 2
  If a_seconde > 59 Then
    Begin
      a_seconde := a_seconde - 60;
      a_minute := 1;
    End;
  a_minute := d_minute + t_minute + a_minute;
  If a_minute >60 Then
    Begin
      a_minute := a_minute - 60;
      a_heure := 1;
    End;
  a_heure := d_heure + t_heure + a_heure;
  If a_heure > 24 Then
    Begin
      a_heure := a_heure - 24;
      J := 1;
    End;
  Writeln('Le train arrive à ', a_heure, ' heures, ', a_minute, ' minutes et ', a_seconde,
          ' secondes.');
  // Étape 3
  Readln;
End.