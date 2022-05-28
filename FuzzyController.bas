Public Const s As Double=0, ms As Double=0.2, m As Double=0.4, ml As Double=0.6, l As Double=0.8
Public Const nl As Double=-0.2, nm As Double=-0.1, z As Double=0, pm As Double=0.1, pl As Double=0.2
Public Const max As Integer=150, smax As Integer=60, mmax As Integer=50, smin As Integer =  40, mmin As Integer=10, min As Integer=0

Sub Main
 SetTimeStep 0.1
' SetMobotPosition(0,0.9,8,90)
 diff=0
 prv=0
 For t=0 To 20000
 s6=MeasureRange(0,6,0)
 s7=MeasureRange(0,7,0)
 s8=MeasureRange(0,8,0)
 s9=MeasureRange(0,9,0)
 s10=MeasureRange(0,10,0)
 s11=MeasureRange(0,11,0)
 Debug.Print (s6)
 Debug.Print (s7)
 Debug.Print (s8)
 Debug.Print (s9)
 Debug.Print (s10)
 Debug.Print (s11)
 Debug.Print mind(s6,s7,s8,s9,s10,s11)
 dist = mind(s6,s7,s8,s9,s10,s11)

 Debug.Print (dist)
 df=dist-prv
 Debug.Print(df)

 Dim dM(4)
 dM(0) = f1(dist,s,ms)
 dM(1) = f2(dist,s,ms,m)
 dM(2) = f2(dist,ms,m,ml)
 dM(3) = f2(dist,m,ml,l)
 dM(4) = f3(dist,ml,l)

 Debug.Print (dM(0))
 Debug.Print (dM(1))
 Debug.Print (dM(2))
 Debug.Print (dM(3))
 Debug.Print (dM(4))

 Dim Differ(4)
 Differ(0) = f1(df,nl,nm)
 Differ(1) = f2(df,nl,nm,z)
 Differ(2) = f2(df,nm,z,pm)
 Differ(3) = f2(df,z,pm,pl)
 Differ(4) = f3(df,pm,pl)

 Debug.Print (Differ(0))
 Debug.Print (Differ(1))
 Debug.Print (Differ(2))
 Debug.Print (Differ(3))
 Debug.Print (Differ(4))


 Dim leftvel(4,4)
 leftvel(0,0)=max
 leftvel(0,1)=smax
 leftvel(0,2)=mmax
 leftvel(0,3)=smin
 leftvel(0,4)=mmin
 leftvel(1,0)=smax
 leftvel(1,1)=smax
 leftvel(1,2)=smax
 leftvel(1,3)=mmax
 leftvel(1,4)=mmax
 leftvel(2,0)=smin
 leftvel(2,1)=mmin
 leftvel(2,2)=mmin
 leftvel(2,3)=mmin
 leftvel(2,4)=min
 leftvel(3,0)=smin
 leftvel(3,1)=smin
 leftvel(3,2)=mmin
 leftvel(3,3)=mmin
 leftvel(3,4)=min
 leftvel(4,0)=smin
 leftvel(4,1)=mmin
 leftvel(4,2)=mmin
 leftvel(4,3)=min
 leftvel(4,4)=min




Dim rightvel(4,4)
 rightvel(0,0)=min
 rightvel(0,1)=min
 rightvel(0,2)=mmin
 rightvel(0,3)=mmin
 rightvel(0,4)=smin
 rightvel(1,0)=min
 rightvel(1,1)=mmin
 rightvel(1,2)=mmin
 rightvel(1,3)=smin
 rightvel(1,4)=smin
 rightvel(2,0)=mmin
 rightvel(2,1)=min
 rightvel(2,2)=mmin
 rightvel(2,3)=smin
 rightvel(2,4)=mmin
 rightvel(3,0)=mmax
 rightvel(3,1)=mmax
 rightvel(3,2)=smax
 rightvel(3,3)=smax
 rightvel(3,4)=max
 rightvel(4,0)=mmin
 rightvel(4,1)=smin
 rightvel(4,2)=mmax
 rightvel(4,3)=smax
 rightvel(4,4)=max



num1=0
den1=0.000000001
For i=0 To 4
For j=0 To 4
premise = Minimum(dM(i),Differ(j))
Debug.Print (premise)
sum=premise*leftvel(i,j)
den1=den1+premise
Debug.Print(den1)
num1=num1+sum
Next
Next
Debug.Print(num1)
Debug.Print(den1)
wleft=num1/den1
Debug.Print(wleft)


num2=0
den2=0.000000001
For i=0 To 4
For j=0 To 4
premise = Minimum(dM(i),Differ(j))
sum=premise*rightvel(i,j)
den2=den2+premise
Debug.Print(den2)
num2=num2+sum
Next
Next
Debug.Print(den2)
Debug.Print(num2)
wright=num2/den2
Debug.Print(wright)

SetWheelSpeed(0,wleft,wright)
StepForward

prv = dist
Debug.Print(prv)
Next

End Sub
Function f1(d,y,z)
  If d>=y And d<=z Then
  f1 = (d-z)/(y-z)
  ElseIf d<y Then
  f1=1
  ElseIf d>z Then
  f1=0
  End If
End Function
Function f2(d,x,y,z)
 If d>=x And d<=z Then
 unit=1
 Else
 unit=0
 End If
 If d>=x And d<=y Then
 f2=(d-x)/(y-x)*unit
 ElseIf d>=y And d<=z Then
 f2=(d-z)/(y-z)*unit
 End If

End Function
Function f3(d,x,y)
 If d>=x And d<=y Then
  f3=(d-x)/(y-x)
  ElseIf d>y Then
  f3=1
  ElseIf d<x Then
  f3=0
  End If
End Function
Function mind(l,m,n,o,p,q)
 If l < 0 Then
 l=l*-1
 End If
 If m < 0 Then
 m=m*-1
 End If
 If n < 0 Then
 n=n*-1
 End If
 If o < 0 Then
 o=o*-1
 End If
 If p < 0 Then
 p=p*-1
 End If
 If q < 0 Then
 q=q*-1
 End If
 If l<=m And l<=n And l<=o And l<=p And l<=q Then
 mind=l
 ElseIf m<=l And m<=n And m<=o And m<=p And m<=q Then
 mind=m
 ElseIf n<=m And n<=l And n<=o And n<=p And n<=q Then
 mind=n
 ElseIf o<=m And o<=n And o<=l And o<=p And o<=q Then
 mind=o
 ElseIf p<=m And p<=n And p<=l And p<=o And p<=q Then
 mind=p
 ElseIf q<=m And q<=n And q<=l And q<=p And q<=l Then
 mind=q
 End If
End Function
Function Minimum(a,b)
If a<b Then
Minimum=a
Else
Minimum=b
End If
End Function
