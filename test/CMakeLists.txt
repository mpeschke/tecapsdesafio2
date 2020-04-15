include_directories(../src)

add_executable(
    unit_tests
    ../src/desafio2.c
    tests_desafio2.c
    )

# Template para testes de Analisadores Léxicos
function(do_test lexicalanalyser target testid arg1 arg2 result)
  add_test(NAME ${lexicalanalyser}-Test-${testid} COMMAND ${target} ${arg1} "${arg2}")
  set_tests_properties(${lexicalanalyser}-Test-${testid}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction(do_test)

# Testes de sucesso - conversões onde o número já é o número - não precisa ser traduzido a partir da letra.
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 0 1 "000000000000000000000000000000" "Valor retornado: TRUE. Número '000000000000000000000000000000' traduzido para '000000000000000000000000000000'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 1 1 "111111111111111111111111111111" "Valor retornado: TRUE. Número '111111111111111111111111111111' traduzido para '111111111111111111111111111111'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 2 1 "222222222222222222222222222222" "Valor retornado: TRUE. Número '222222222222222222222222222222' traduzido para '222222222222222222222222222222'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 3 1 "333333333333333333333333333333" "Valor retornado: TRUE. Número '333333333333333333333333333333' traduzido para '333333333333333333333333333333'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 4 1 "444444444444444444444444444444" "Valor retornado: TRUE. Número '444444444444444444444444444444' traduzido para '444444444444444444444444444444'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 5 1 "555555555555555555555555555555" "Valor retornado: TRUE. Número '555555555555555555555555555555' traduzido para '555555555555555555555555555555'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 6 1 "666666666666666666666666666666" "Valor retornado: TRUE. Número '666666666666666666666666666666' traduzido para '666666666666666666666666666666'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 7 1 "777777777777777777777777777777" "Valor retornado: TRUE. Número '777777777777777777777777777777' traduzido para '777777777777777777777777777777'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 8 1 "888888888888888888888888888888" "Valor retornado: TRUE. Número '888888888888888888888888888888' traduzido para '888888888888888888888888888888'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 9 1 "999999999999999999999999999999" "Valor retornado: TRUE. Número '999999999999999999999999999999' traduzido para '999999999999999999999999999999'")

# Testes de sucesso - conversões a partir de letras.
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 10 1 "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" "Valor retornado: TRUE. Número 'AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA' traduzido para '222222222222222222222222222222'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 11 1 "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBB" "Valor retornado: TRUE. Número 'BBBBBBBBBBBBBBBBBBBBBBBBBBBBBB' traduzido para '222222222222222222222222222222'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 12 1 "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCC" "Valor retornado: TRUE. Número 'CCCCCCCCCCCCCCCCCCCCCCCCCCCCCC' traduzido para '222222222222222222222222222222'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 13 1 "DDDDDDDDDDDDDDDDDDDDDDDDDDDDDD" "Valor retornado: TRUE. Número 'DDDDDDDDDDDDDDDDDDDDDDDDDDDDDD' traduzido para '333333333333333333333333333333'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 14 1 "EEEEEEEEEEEEEEEEEEEEEEEEEEEEEE" "Valor retornado: TRUE. Número 'EEEEEEEEEEEEEEEEEEEEEEEEEEEEEE' traduzido para '333333333333333333333333333333'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 15 1 "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF" "Valor retornado: TRUE. Número 'FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF' traduzido para '333333333333333333333333333333'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 16 1 "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG" "Valor retornado: TRUE. Número 'GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG' traduzido para '444444444444444444444444444444'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 17 1 "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHH" "Valor retornado: TRUE. Número 'HHHHHHHHHHHHHHHHHHHHHHHHHHHHHH' traduzido para '444444444444444444444444444444'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 18 1 "IIIIIIIIIIIIIIIIIIIIIIIIIIIIII" "Valor retornado: TRUE. Número 'IIIIIIIIIIIIIIIIIIIIIIIIIIIIII' traduzido para '444444444444444444444444444444'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 19 1 "JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ" "Valor retornado: TRUE. Número 'JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ' traduzido para '555555555555555555555555555555'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 20 1 "KKKKKKKKKKKKKKKKKKKKKKKKKKKKKK" "Valor retornado: TRUE. Número 'KKKKKKKKKKKKKKKKKKKKKKKKKKKKKK' traduzido para '555555555555555555555555555555'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 21 1 "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLL" "Valor retornado: TRUE. Número 'LLLLLLLLLLLLLLLLLLLLLLLLLLLLLL' traduzido para '555555555555555555555555555555'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 22 1 "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" "Valor retornado: TRUE. Número 'MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM' traduzido para '666666666666666666666666666666'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 23 1 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNN" "Valor retornado: TRUE. Número 'NNNNNNNNNNNNNNNNNNNNNNNNNNNNNN' traduzido para '666666666666666666666666666666'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 24 1 "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" "Valor retornado: TRUE. Número 'OOOOOOOOOOOOOOOOOOOOOOOOOOOOOO' traduzido para '666666666666666666666666666666'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 25 1 "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPP" "Valor retornado: TRUE. Número 'PPPPPPPPPPPPPPPPPPPPPPPPPPPPPP' traduzido para '777777777777777777777777777777'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 26 1 "QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ" "Valor retornado: TRUE. Número 'QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ' traduzido para '777777777777777777777777777777'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 27 1 "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" "Valor retornado: TRUE. Número 'RRRRRRRRRRRRRRRRRRRRRRRRRRRRRR' traduzido para '777777777777777777777777777777'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 28 1 "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS" "Valor retornado: TRUE. Número 'SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS' traduzido para '777777777777777777777777777777'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 29 1 "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT" "Valor retornado: TRUE. Número 'TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT' traduzido para '888888888888888888888888888888'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 30 1 "UUUUUUUUUUUUUUUUUUUUUUUUUUUUUU" "Valor retornado: TRUE. Número 'UUUUUUUUUUUUUUUUUUUUUUUUUUUUUU' traduzido para '888888888888888888888888888888'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 31 1 "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" "Valor retornado: TRUE. Número 'VVVVVVVVVVVVVVVVVVVVVVVVVVVVVV' traduzido para '888888888888888888888888888888'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 32 1 "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" "Valor retornado: TRUE. Número 'XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX' traduzido para '999999999999999999999999999999'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 33 1 "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" "Valor retornado: TRUE. Número 'WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW' traduzido para '999999999999999999999999999999'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 34 1 "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYY" "Valor retornado: TRUE. Número 'YYYYYYYYYYYYYYYYYYYYYYYYYYYYYY' traduzido para '999999999999999999999999999999'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 35 1 "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ" "Valor retornado: TRUE. Número 'ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ' traduzido para '999999999999999999999999999999'")

# Testes de sucesso - conversões a partir de outros caracteres válidos.
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 36 1 "------------------------------" "Valor retornado: TRUE. Número '------------------------------' traduzido para '------------------------------'")

# Testes de sucesso - conversões válidas, com nomes aleatórios.
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 37 1 "55-11-MATHEUS-AZEVEDO" "Valor retornado: TRUE. Número '55-11-MATHEUS-AZEVEDO' traduzido para '55-11-6284387-2938336'")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 38 1 "55-11-GUSTAVO-CALDAS" "Valor retornado: TRUE. Número '55-11-GUSTAVO-CALDAS' traduzido para '55-11-4878286-225327'")

# Testes de sucesso - usuário digitou comando para terminar a aplicação.
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 39 1 "00000" "Valor retornado: TRUE.")
# O comando ignora espaços
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 40 1 " 00000" "Valor retornado: TRUE.")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 41 1 "                         00000" "Valor retornado: TRUE.")
do_test("translatecommandLexicalAnalyser_ValidScenario" unit_tests 42 1 "                       00000  " "Valor retornado: TRUE.")

# Testes de falha - o número é maior que o máximo de 30 caracteres.
do_test("translatecommandLexicalAnalyser_InvalidScenario" unit_tests 0 1 "0000000000000000000000000000000" "Valor retornado: FALSE.")
do_test("translatecommandLexicalAnalyser_InvalidScenario" unit_tests 1 1 "1111111111111111111111111111111" "Valor retornado: FALSE.")
do_test("translatecommandLexicalAnalyser_InvalidScenario" unit_tests 2 1 "2222222222222222222222222222222" "Valor retornado: FALSE.")
do_test("translatecommandLexicalAnalyser_InvalidScenario" unit_tests 3 1 "3333333333333333333333333333333" "Valor retornado: FALSE.")
do_test("translatecommandLexicalAnalyser_InvalidScenario" unit_tests 4 1 "4444444444444444444444444444444" "Valor retornado: FALSE.")
do_test("translatecommandLexicalAnalyser_InvalidScenario" unit_tests 5 1 "5555555555555555555555555555555" "Valor retornado: FALSE.")
do_test("translatecommandLexicalAnalyser_InvalidScenario" unit_tests 6 1 "6666666666666666666666666666666" "Valor retornado: FALSE.")
do_test("translatecommandLexicalAnalyser_InvalidScenario" unit_tests 7 1 "7777777777777777777777777777777" "Valor retornado: FALSE.")
do_test("translatecommandLexicalAnalyser_InvalidScenario" unit_tests 8 1 "8888888888888888888888888888888" "Valor retornado: FALSE.")
do_test("translatecommandLexicalAnalyser_InvalidScenario" unit_tests 9 1 "9999999999999999999999999999999" "Valor retornado: FALSE.")

# Testes de falha - além do número, o usuário digitou caracteres inválidos.
do_test("translatecommandLexicalAnalyser_InvalidScenario" unit_tests 10 1 "+55-11-MATHEUS-AZEVEDO" "Valor retornado: FALSE.")
do_test("translatecommandLexicalAnalyser_InvalidScenario" unit_tests 11 1 "+55 11 MATHEUS AZEVEDO" "Valor retornado: FALSE.")
do_test("translatecommandLexicalAnalyser_InvalidScenario" unit_tests 12 1 " 55-11-GUSTAVO-CALDAS" "Valor retornado: FALSE.")
do_test("translatecommandLexicalAnalyser_InvalidScenario" unit_tests 13 1 "55-11-GUSTAVO CALDAS" "Valor retornado: FALSE.")
do_test("translatecommandLexicalAnalyser_InvalidScenario" unit_tests 14 1 "55-11-GUSTAVO CALDAS " "Valor retornado: FALSE.")
do_test("translatecommandLexicalAnalyser_InvalidScenario" unit_tests 15 1 "55-11-matheus-AZEVEDO" "Valor retornado: FALSE.")
