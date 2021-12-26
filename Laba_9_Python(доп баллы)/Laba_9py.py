def create_list_no_repetitions(list_no_repetitions): # функція видалення усіх дублікатів слів
    i = 0
    while i < len(list_no_repetitions):
        j = 0
        while j < len(list_no_repetitions):
            if list_no_repetitions[i] == list_no_repetitions[j]:
                if i != j:
                    list_no_repetitions.pop(j)
                    j -= 1
            j += 1
        i += 1
    print('Введений рядок без дубликатiв: ', list_no_repetitions, '\n')
    return list_no_repetitions


def write_list_number_repetitions(list_no_repetitions, list): # функція виводу кожного слова рядку без дубликатiв, та кiлькiсть повторень
    i = 0
    while i < len(list_no_repetitions):
        print('Слово: ', list_no_repetitions[i], ' ' , 'Кiлькiсть повторень: ', list.count(list_no_repetitions[i]))
        i += 1


s = input('Введiть рядок символiв: ')
list = s.split()
print()  # відокремлення блоків виводу
print('Введений рядок: ', list, '\n')
list_no_repetitions = list[:]  # оператор зрізу для посилання копії, що дублюється, не на початковий список, а на копію списку
create_list_no_repetitions(list_no_repetitions)  # функція видалення усіх дублікатів слів
write_list_number_repetitions(list_no_repetitions, list)  # функція виводу кожного слова рядку без дубликатiв, та кiлькiсть повторень
print()  # відокремлення блоків виводу


