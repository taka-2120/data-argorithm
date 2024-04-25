import Foundation

func insertionSort(_ _array: [Int], length: Int) {
    var array = _array
    for i in 0 ... length - 1 {
        let value = array[i]
        var index = i - 1
        while index >= 0 && array[index] > value {
            array[index + 1] = array[index]
            index = index - 1
        }
        array[index + 1] = value
        print(array)
    }
}

print("Enter length for array >> ")
guard let input = readLine(), let length = Int(input) else { exit(0) }
print("Enter number array >> ")
guard let arrayStr = readLine() else { exit(0) }
let array = arrayStr.split(separator: " ").map { Int($0)! }
insertionSort(array, length: length)
