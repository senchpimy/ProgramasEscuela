package main

import (
	"fmt"
//	"strconv"
//	"strings"
	"math/rand"
	"time"
)

func main() {
//	var val string
//	var num int
fmt.Println("Inicio")
	comparaciones :=0
	start := time.Now()
	lista :=CreateList()
	elapsed := time.Since(start)
	fmt.Printf("La creacion de la Lista tomo: %s\n", elapsed)
	start = time.Now()
	Bublesort(lista,&comparaciones)
	elapsed = time.Since(start)
	fmt.Printf("Ordenar la Lista tomo: %s\n", elapsed)
	fmt.Println("Se hicieron comparaciones:", comparaciones)
	fmt.Println(lista[:100])

}


func Bublesort(slice []int,comparaciones *int) {
	for i := 0; i < len(slice); i++ {
		for j := 0; j < len(slice)-1; j++ {
		//for j := 0; j < len(slice)-1-i; j++ {
			if slice[j] > slice[j+1] {
				*comparaciones++
				slice[j], slice[j+1] = slice[j+1], slice[j]
			}
		}
	}

}

func CreateList()(lista []int){
	s1 := rand.NewSource(time.Now().UnixNano())
	r1 := rand.New(s1)

	slice := make([]int, 10_000)
	for j := range slice{
		slice[j]=r1.Intn(10_000)
	}
	return slice
}
