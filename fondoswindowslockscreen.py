import os
import random
import string
import shutil
#
#Replace X with your own data
#
fondos_de_pantalla=r"C:\Users\XXXXX\AppData\Local\Packages\Microsoft.Windows.ContentDeliveryManager_XXXXXX\LocalState\Assets"
carpeta_destino=r"C:\Users\XXXXX\OneDrive\Imágenes"
archivos=os.listdir(fondos_de_pantalla)
archivos_correctpath=[]
for archivo in archivos:
	ubicacion=os.path.join(fondos_de_pantalla,archivo)
	archivos_correctpath.append(ubicacion)

def LimpiarArchivos(archivos):
	for archivo in archivos:
		if os.stat(archivo).st_size/1024<1000:
			continue
		else:
			archivos.remove(archivo)
	return archivos

def CopiarArchivos(archivos):
	for archivo in archivos:
		nombre,extension=os.path.splitext(archivo)
		nuevoNombre=carpeta_destino+"\\"+"".join((random.choice(string.ascii_lowercase) for x in range(25)))+".jpg"
		shutil.copy(archivo,nuevoNombre)

CopiarArchivos(LimpiarArchivos(archivos_correctpath))
