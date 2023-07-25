package main

import (
	"fmt"
	"os"
	"bufio"
	"strings"
	//"strconv"
)

func getline(s1 string) string{
	in := bufio.NewReader(os.Stdin)
	s1, _ = in.ReadString('\n')
	s1 = strings.TrimSpace(s1)
	return s1
}

func main() {
	var s1, s2 string
	s1 = getline(s1)
	s2 = getline(s2)
	s2 = s1 + " " + s2
	fmt.Println(s2)

	/////////////////////////////// another Easy way //////////////////////////

	in := bufio.NewScanner(os.Stdin)
	in.Scan()
	s1:=in.Text()
}
