Function Fibo(N:Longint): Longint;
//Calcule le n''ieme terme de la suite de FIBONACCI
Var
  der,avder,elem : Longint;
  i : Longint;
Begin //Fibo
  der := 1;
  avder := 1;
  elem := 2;
  For i:=3 To N Do
    Begin
      elem := avder+der;
      avder := der;
      der := elem
    End;
  Fibo := der;
End;  //Fibo 