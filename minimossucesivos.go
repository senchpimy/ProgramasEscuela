package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	fmt.Println("Inicio")
	comparaciones :=0
	start := time.Now()
	lista :=CreateList()
	fmt.Println(lista[:100])
	elapsed := time.Since(start)
	fmt.Printf("La creacion de la Lista tomo: %s\n", elapsed)
	start = time.Now()
	MinimoSucesivo(lista,&comparaciones)
	elapsed = time.Since(start)
	fmt.Printf("Ordenar la Lista tomo: %s\n", elapsed)
	fmt.Println("Se hicieron comparaciones:", comparaciones)
	fmt.Println(lista[:100])
	fmt.Println(lista[5000])
	fmt.Println(lista[9900:])

}

func MinimoSucesivo(slice []int, comparaciones *int) {
    for i := 0; i < len(slice); i++ {
        menor := i
        for j := i + 1; j < len(slice); j++ {
            if slice[j] < slice[menor] {
            	*comparaciones++
                menor = j
            }
        }
        if menor != i {
            slice[i], slice[menor] = slice[menor], slice[i]
        }
    }
}

func CreateList()(lista []int){
	s1 := rand.NewSource(time.Now().UnixNano())
	r1 := rand.New(s1)

	slice := make([]int, 10_000)
	_ =r1.Intn(10_000)
	for j := range slice{
		slice[j]=r1.Intn(10_000)
	}
	return slice
}
