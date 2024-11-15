
# 定義執行檔名稱
OUTPUT="main"

# 尋找所有的 .cpp 檔案
SOURCES=$(find . -name "*.cpp")

# 編譯所有的 .cpp 檔案
g++ $SOURCES -o $OUTPUT

# 檢查編譯是否成功
if [ $? -eq 0 ]; then
    echo "Compilation successful!"
    echo "Running the program:"
    ./main
else
    echo "Compilation failed."
fi