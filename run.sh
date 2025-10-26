if [ "$#" -lt 1 ]; then
    echo "provide id of problem statement"
    exit 1
fi

cd $1 
go run main.go 
