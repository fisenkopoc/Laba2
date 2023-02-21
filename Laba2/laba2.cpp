#include <windows.h>

#include <direct.h>

#include <stdio.h>

#include <tchar.h>
#include <locale.h>



// Дает начальное значение

TCHAR szDrive[] = _T(" A:");



// Возможно, вы захотите использовать версию wmain()

int main(void)

{
	setlocale(LC_ALL, "Rus");

	DWORD uDriveMask = GetLogicalDrives();

	printf("Битовая маска логических дисков в шестнадцатеричном формате: %0X\n", uDriveMask);

	printf("Битовая маска логических дисков в десятичном формате: %d\n", uDriveMask);

	if (uDriveMask == 0)

		printf("Ошибка GetLogicalDrives() с кодом сбоя: %d\n", GetLastError());

	else

	{

		printf("Эта машина имеет следующие логические диски:\n");

		while (uDriveMask)

		{

			// Используйте побитовое И, 1-доступно, 0-недоступно

			if (uDriveMask & 1)

				printf("%S ", (const char*)szDrive);

			// увеличьте, проверьте следующий диск

			++szDrive[1];

			// сдвиньте двоичную битовую маску вправо

			uDriveMask >>= 1;

		}

		printf("\n ");

	}

	return 0;

}