# module6 -> lesson2 -> step8
# Проверка знаков частного и остатка двух чисел при делении

a = int(input())
b = int(input())

print(f' {a} //  {b} =  {  a  //   b } (остаток  {  a  %   b })')
print(f' {a} // {-b} = {   a  // (-b)} (остаток {   a  % (-b)})')
print(f'{-a} //  {b} = { (-a) //   b } (остаток  {(-a) %   b })')
print(f'{-a} // {-b} =  {(-a) // (-b)} (остаток { (-a) % (-b)})')
