/* * [正規コード] ツールによって自動生成されたドライバ層 
 * ※このファイルは直接編集しないのが「正規」のルールです
 */

#include <stdio.h>

// モデル(.nmdl)から定義されたシグナル値（擬似）
int IlluminanceValue = 0; 

// ライトの物理的な制御関数（OT層への橋渡し）
void Set_Hardware_Light(int status) {
    if (status == 1) printf("Hardware: Light ON\n");
    else printf("Hardware: Light OFF\n");
}

// 照度センサーの値を更新する関数
void Update_Illuminance(int value) {
    IlluminanceValue = value;
}

