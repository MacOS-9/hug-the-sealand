//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#define sealandBlue 0
#define beniuBlue 0
#define stonkFishBlue 0
#define stonkFishHappinessDecrease 0.125
TForm1 *Form1;
int itemCount, money;
float sealandHunger = 112, sealandHappiness = 112, sealandHappinessDecrease = 0.125;
float beniuHunger = 112, beniuHappiness = 112, beniuHappinessDecrease = 0.125;
float stonkFishHappiness = 112;
float sealandRed[2] = {0, 0};
float beniuRed[2] = {0, 0};
float stonkFishRed = 0;
float sealandGreen[2] = {255, 255};
float beniuGreen[2] = {255, 255};
float stonkFishGreen = 255;
bool beniuCaught, stonkFishCaught, frenchFlagBought, polishFlagBought, WineHQBought;
bool frenchVisible, polishVisible, WineHQVisible, SMG4Visible;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
 howToPlay->Top = 16;
 itemsBox->MultiSelect = false;
 Form1->Top = (Screen->DesktopTop + Form1->Top) / 2;
 Form1->Left = (Screen->DesktopWidth - Form1->Width) / 2;
 ground->Color = TColor(RGB(0, 255, 0));
 treeLog1->Color = TColor(RGB(161, 73, 22));
 treeLog2->Color = TColor(RGB(161, 73, 22));
 treeLeave1->Color = TColor(RGB(0, 255, 0));
 treeLeave2->Color = TColor(RGB(0, 255, 0));
 treeLeave3->Color = TColor(RGB(0, 255, 0));
 treeLeave4->Color = TColor(RGB(0, 255, 0));
 treeLeave5->Color = TColor(RGB(0, 255, 0));
 treeLeave6->Color = TColor(RGB(0, 255, 0));
 stonkFishHungerBar->Color = TColor(RGB(0, 255, 0));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::exitButtonClick(TObject *Sender)
{
 Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::playButtonClick(TObject *Sender)
{
 exitButton->Left = 8;
 exitButton->Top = 8;
 sealandHappiness = 112;
 sealandHunger = 112;
 beniuHappiness = 112;
 beniuHunger = 112;
 stonkFishHappiness = 112;
 money = 0;
 itemCount = 3;
 itemsBox->Clear();
 for (int i = 0; i < itemCount; i++)
  itemsBox->AddItem("Baguette", NULL);
 workButton->Caption = "Work at the park";
 workButton->Visible = true;
 workButton->Left = 88;
 shopButton->Caption = "Go to the shop";
 shopButton->Visible = true;
 shopButton->Left = 192; 
 beniuCaught = false;
 stonkFishCaught = false;
 tryAgainButton->Visible = false;
 titleScreenName->Visible = false;
 playButton->Visible = false;
 howToPlayButton->Visible = false;
 sealand->Visible = true;
 sealandHappinessBarLabel->Visible = true;
 sealandHappinessBar->Visible = true;
 sealandDeath->Visible = false;
 sealandDeathCause->Visible = false;
 workButton->Visible = true;
 shopButton->Visible = true;
 sealandHungerBarLabel->Visible = true;
 sealandHungerBar->Visible = true;
 statsTimer->Enabled = true;
 gameTimer->Enabled = true;
 workButton->Caption = "Work at the park";
 Form1->Color = cl3DDkShadow;
 ground->Visible = false;
 treeLog1->Visible = false;
 treeLog2->Visible = false;
 treeLeave1->Visible = false;
 treeLeave2->Visible = false;
 treeLeave3->Visible = false;
 treeLeave4->Visible = false;
 treeLeave5->Visible = false;
 treeLeave6->Visible = false;
 statsLabel->Visible = true;
 itemsBox->Visible = true;
 itemsLabel->Visible = true;
 useItem->Visible = true;
 frenchVisible = false;
 polishVisible = false;
 WineHQVisible = false;
 WineHQBought = false;
 frenchFlagBought = false;
 polishFlagBought = false;
 buyWineHQButton->Enabled = true;
 WineHQPrice->Caption = "40z³";
 buyPolishFlagButton->Enabled = true;
 polishFlagPrice->Caption = "30z³";
 buyFrenchFlagButton->Enabled = true;
 frenchFlagPrice->Caption = "30z³";
 buySMG4PlushieButton->Enabled = true;
 SMG4PlushiePrice->Caption = "165z³";
 SMG4Visible = false;
 frenchFlag->Visible = false;
 polishFlag->Visible = false;
 window->Visible = false;
 SMG4Plushie->Visible = false;
 beniu->Visible = beniuCaught;
 stonkFish->Visible = stonkFishCaught;
 useOnSealand->Visible = true;
 useOnBeniu->Visible = beniuCaught;
 useOnStonkFish->Visible = stonkFishCaught;
 beniuHappinessBarLabel->Visible = beniuCaught;
 stonkFishHappinessBarLabel->Visible = stonkFishCaught;
 beniuHappinessBar->Visible = beniuCaught;
 stonkFishHappinessBar->Visible = stonkFishCaught;
 beniuHungerBarLabel->Visible = beniuCaught;
 stonkFishHungerBarLabel->Visible = stonkFishCaught;
 beniuHungerBar->Visible = beniuCaught;
 stonkFishHungerBar->Visible = stonkFishCaught;
 sealand->Top = 320;
 stonkFish->Top = 320;
 beniu->Top = 320;
 sealand->Picture->LoadFromFile(".\\assets\\sealand.jpg");
 stonkFish->Picture->LoadFromFile(".\\assets\\stonkFish.jpg");
 beniu->Picture->LoadFromFile(".\\assets\\beniu.jpg");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::gameTimerTimer(TObject *Sender)
{
 sealandHappinessBar->Width = sealandHappiness;
 sealandHungerBar->Width = sealandHunger;
 beniuHappinessBar->Width = beniuHappiness;
 beniuHungerBar->Width = beniuHunger;
 stonkFishHappinessBar->Width = stonkFishHappiness;
 sealandHappinessBar->Color = TColor(RGB(sealandRed[0], sealandGreen[0], sealandBlue));
 sealandHungerBar->Color = TColor(RGB(sealandRed[1], sealandGreen[1], sealandBlue));
 beniuHappinessBar->Color = TColor(RGB(beniuRed[0], beniuGreen[0], beniuBlue));
 beniuHungerBar->Color = TColor(RGB(beniuRed[1], beniuGreen[1], beniuBlue));
 stonkFishHappinessBar->Color = TColor(RGB(stonkFishRed, stonkFishGreen, stonkFishBlue));
 statsLabel->Caption = "Money: " + IntToStr(money) + "z³\nItems: " + IntToStr(itemCount);
 if (sealandHappiness > 112)
  sealandHappiness = 112;
 if (sealandHappiness < 1 || sealandHunger < 1 || beniuHappiness < 1 ||
     beniuHunger < 1 || stonkFishHappiness < 1) {
  if (sealandHappiness < 1)
   sealandDeathCause->Caption = "Reason: Sealand was unhappy.";
  else if (sealandHunger < 1)
   sealandDeathCause->Caption = "Reason: Sealand died of hunger.";
  else if (beniuHappiness < 1)
   sealandDeathCause->Caption = "Reason: Beniu died of unhappiness and Sealand saw it, causing him to die.";
  else if (beniuHunger < 1)
   sealandDeathCause->Caption = "Reason: Beniu died of hunger and Sealand saw it, causing him to die.";
  else if (stonkFishHappiness < 1)
   sealandDeathCause->Caption = "Reason: StonkFish was unhappy and Alt+F4'd the entire world.";
  exitButton->Left = howToPlayButton->Left;
  exitButton->Top = 176;
  sealand->Visible = false;
  sealandHappinessBarLabel->Visible = false;
  sealandHungerBarLabel->Visible = false;
  sealandHappinessBar->Visible = false;
  sealandHungerBar->Visible = false;
  workButton->Visible = false;
  shopButton->Visible = false;
  sealandDeath->Visible = true;
  sealandDeathCause->Visible = true;
  tryAgainButton->Visible = true;
  statsTimer->Enabled = false;
  gameTimer->Enabled = false;
  statsLabel->Visible = false;
  buyBaguetteButton->Visible = false;
  buyFrenchFlagButton->Visible = false;
  buyFrenchFriesButton->Visible = false;
  buyItalianPizzaButton->Visible = false;
  buyPierogiButton->Visible = false;
  buyPolishFlagButton->Visible = false;
  buySMG4PlushieButton->Visible = false;
  buyWineHQButton->Visible = false;
  baguettePrice->Visible = false;
  frenchFlagPrice->Visible = false;
  frenchFriesPrice->Visible = false;
  italianPizzaPrice->Visible = false;
  pierogiPrice->Visible = false;
  polishFlagPrice->Visible = false;
  SMG4PlushiePrice->Visible = false;
  WineHQPrice->Visible = false;
  itemsBox->Visible = false;
  itemsLabel->Visible = false;
  useItem->Visible = false;
  frenchFlag->Visible = false;
  polishFlag->Visible = false;
  window->Visible = false;
  SMG4Plushie->Visible = false;
  useOnSealand->Visible = false;
  useOnBeniu->Visible = false;
  useOnStonkFish->Visible = false;
  beniu->Visible = false;
  stonkFish->Visible = false;
  beniuHappinessBarLabel->Visible = false;
  stonkFishHappinessBarLabel->Visible = false;
  beniuHappinessBar->Visible = false;
  stonkFishHappinessBar->Visible = false;
  beniuHungerBarLabel->Visible = false;
  stonkFishHungerBarLabel->Visible = false;
  beniuHungerBar->Visible = false;
  stonkFishHungerBar->Visible = false;
 }
 sealandDeathCause->Left = (Form1->Width - sealandDeathCause->Width) / 2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::sealandClick(TObject *Sender)
{
 if (sealandHappinessBar->Width < 100)
  sealandHappiness += 12;
 else
  sealandHappiness = 112;
 if (workButton->Caption == "Go back home")
  money += 4;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::statsTimerTimer(TObject *Sender)
{
 if (sealandHappinessBar->Width > 0) {
  if (workButton->Caption == "Work at the park" && shopButton->Caption == "Go to the shop")
   sealandHappiness -= sealandHappinessDecrease;
  else if (workButton->Caption == "Go back home" || shopButton->Caption == "Go back home")
   if (sealandHappinessDecrease > 0.0625)
    sealandHappiness -= 0.0625;
   else
    sealandHappiness -= sealandHappinessDecrease;
 }
 if (sealandHappinessBar->Width > 48) {
  sealandGreen[0] = sealandHappinessBar->Width * 2;
  sealandRed[0] = sealandHappinessBar->Width * 2.75;
 } else {
  sealandGreen[0] = 24;
  sealandRed[0] = 132;
 }
 sealandHunger -= 0.0625;
 if (sealandHungerBar->Width > 48) {
  sealandGreen[1] = sealandHungerBar->Width * 2;
  sealandRed[1] = sealandHungerBar->Width * 2.75;
 } else {
  sealandGreen[1] = 24;
  sealandRed[1] = 132;
 }
 if (beniuCaught) {
  if (beniuHappinessBar->Width > 0) {
   if (workButton->Caption == "Work at the park" && shopButton->Caption == "Go to the shop")
    beniuHappiness -= beniuHappinessDecrease;
   else if (workButton->Caption == "Go back home" || shopButton->Caption == "Go back home")
    if (beniuHappinessDecrease > 0.0625)
     beniuHappiness -= 0.0625;
    else
     beniuHappiness -= beniuHappinessDecrease;
  }
  if (beniuHappinessBar->Width > 48) {
   beniuGreen[0] = beniuHappinessBar->Width * 2;
   beniuRed[0] = beniuHappinessBar->Width * 2.75;
  } else {
   beniuGreen[0] = 24;
   beniuRed[0] = 132;
  }
  beniuHunger -= 0.0625;
  if (beniuHungerBar->Width > 48) {
   beniuGreen[1] = beniuHungerBar->Width * 2;
   beniuRed[1] = beniuHungerBar->Width * 2.75;
  } else {
   beniuGreen[1] = 24;
   beniuRed[1] = 132;
  }
 }
 if (stonkFishCaught) {
  if (stonkFishHappinessBar->Width > 0) 
   stonkFishHappiness -= 0.0625;
  if (stonkFishHappiness < 10) {
   for (int i = 0; i < itemsBox->Count; i++) {
    if (itemsBox->Items->Strings[i] == "Fish") {
     stonkFishHappiness = 112;
     itemsBox->Items->Delete(i);
     itemCount--;
     break;
    }
   }
  }
  if (stonkFishHappinessBar->Width > 48) {
   stonkFishGreen = stonkFishHappinessBar->Width * 2;
   stonkFishRed = stonkFishHappinessBar->Width * 2.75;
  } else {
   stonkFishGreen = 24;
   stonkFishRed = 132;
  }
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::workButtonClick(TObject *Sender)
{
 if (workButton->Caption == "Go back home") {
  workButton->Caption = "Work at the park";
  shopButton->Visible = true;
  Form1->Color = cl3DDkShadow;
  ground->Visible = false;
  treeLog1->Visible = false;
  treeLog2->Visible = false;
  treeLeave1->Visible = false;
  treeLeave2->Visible = false;
  treeLeave3->Visible = false;
  treeLeave4->Visible = false;
  treeLeave5->Visible = false;
  treeLeave6->Visible = false;
  frenchFlag->Visible = frenchVisible;
  polishFlag->Visible = polishVisible;
  window->Visible = WineHQVisible;
  SMG4Plushie->Visible = SMG4Visible;
  sealand->Top = 320;
  stonkFish->Top = 320;
  stonkFish->Left = 224;
  beniu->Top = 330;
  beniu->Left = 112;
  sealand->Picture->LoadFromFile(".\\assets\\sealand.jpg");
  stonkFish->Picture->LoadFromFile(".\\assets\\stonkfish.jpg");
  beniu->Picture->LoadFromFile(".\\assets\\beniu.jpg");
 } else {
  workButton->Caption = "Go back home";
  shopButton->Visible = false;
  Form1->Color = clSkyBlue;
  tryAgainButton->Visible = false;
  titleScreenName->Visible = false;
  playButton->Visible = false;
  howToPlayButton->Visible = false;
  ground->Visible = true;
  treeLog1->Visible = true;
  treeLog2->Visible = true;
  treeLeave1->Visible = true;
  treeLeave2->Visible = true;
  treeLeave3->Visible = true;
  treeLeave4->Visible = true;
  treeLeave5->Visible = true;
  treeLeave6->Visible = true;
  frenchFlag->Visible = false;
  polishFlag->Visible = false;
  window->Visible = false;
  SMG4Plushie->Visible = false;
  sealand->Top = 350;
  stonkFish->Top = 350;
  stonkFish->Left = 185;
  beniu->Top = 335;
  sealand->Picture->LoadFromFile(".\\assets\\smallerSealand.jpg");
  stonkFish->Picture->LoadFromFile(".\\assets\\smallerStonkfish.jpg");
  beniu->Picture->LoadFromFile(".\\assets\\smallerBeniu.jpg");
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::shopButtonClick(TObject *Sender)
{
 if (shopButton->Caption == "Go back home") {
  shopButton->Caption = "Go to the shop";
  shopButton->Left = 192;
  workButton->Visible = true;
  buyBaguetteButton->Visible = false;
  buyFrenchFlagButton->Visible = false;
  buyFrenchFriesButton->Visible = false;
  buyItalianPizzaButton->Visible = false;
  buyPierogiButton->Visible = false;
  buyPolishFlagButton->Visible = false;
  buySMG4PlushieButton->Visible = false;
  buyWineHQButton->Visible = false;
  baguettePrice->Visible = false;
  frenchFlagPrice->Visible = false;
  frenchFriesPrice->Visible = false;
  italianPizzaPrice->Visible = false;
  pierogiPrice->Visible = false;
  polishFlagPrice->Visible = false;
  SMG4PlushiePrice->Visible = false;
  WineHQPrice->Visible = false;
  frenchFlag->Visible = frenchVisible;
  polishFlag->Visible = polishVisible;
  window->Visible = WineHQVisible;
  SMG4Plushie->Visible = SMG4Visible;
 } else {
  shopButton->Caption = "Go back home";
  shopButton->Left = 88;
  workButton->Visible = false;
  tryAgainButton->Visible = false;
  titleScreenName->Visible = false;
  playButton->Visible = false;
  howToPlayButton->Visible = false;
  buyBaguetteButton->Visible = true;
  buyFrenchFlagButton->Visible = true;
  buyFrenchFriesButton->Visible = true;
  buyItalianPizzaButton->Visible = true;
  buyPierogiButton->Visible = true;
  buyPolishFlagButton->Visible = true;
  buySMG4PlushieButton->Visible = true;
  buyWineHQButton->Visible = true;
  baguettePrice->Visible = true;
  frenchFlagPrice->Visible = true;
  frenchFriesPrice->Visible = true;
  italianPizzaPrice->Visible = true;
  pierogiPrice->Visible = true;
  polishFlagPrice->Visible = true;
  SMG4PlushiePrice->Visible = true;
  WineHQPrice->Visible = true;
  frenchFlag->Visible = false;
  polishFlag->Visible = false;
  window->Visible = false;
  SMG4Plushie->Visible = false;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::buyWineHQButtonClick(TObject *Sender)
{
 int neededMoney = 40; // temporary variable
 if (money < neededMoney)
  ShowMessage("You do not have enough money to buy this item.\nYou need " +
               IntToStr(neededMoney - money) + "z³ more.");
 if (money >= neededMoney) {
  buyWineHQButton->Enabled = false;
  WineHQPrice->Caption = "Sold out";
  money -= neededMoney;
  WineHQVisible = true;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::buyItalianPizzaButtonClick(TObject *Sender)
{
 int neededMoney = 52; // temporary variable
 if (money < neededMoney)
  ShowMessage("You do not have enough money to buy this item.\nYou need " +
               IntToStr(neededMoney - money) + "z³ more.");
 if (money >= neededMoney) {
  if (itemCount == 100)
   ShowMessage("Item inventory is full.");
  else {
   itemCount++;
   itemsBox->AddItem("Italian pizza", NULL);
   money -= neededMoney;
  }
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::buyFrenchFlagButtonClick(TObject *Sender)
{
 int neededMoney = 30; // temporary variable
 if (money < neededMoney)
  ShowMessage("You do not have enough money to buy this item.\nYou need " +
               IntToStr(neededMoney - money) + "z³ more.");
 if (money >= neededMoney) {
  frenchFlagBought = true;
  buyFrenchFlagButton->Enabled = false;
  frenchFlagPrice->Caption = "Sold out";
  money -= neededMoney;
  sealandHappinessDecrease = sealandHappinessDecrease / 2;
  frenchVisible = true;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::buySMG4PlushieButtonClick(TObject *Sender)
{
 int neededMoney = 165; // temporary variable
 if (money < neededMoney)
  ShowMessage("You do not have enough money to buy this item.\nYou need " +
               IntToStr(neededMoney - money) + "z³ more.");
 if (money >= neededMoney) {
  buySMG4PlushieButton->Enabled = false;
  SMG4PlushiePrice->Caption = "Sold out";
  sealandHappinessDecrease = sealandHappinessDecrease / 2;
  money -= neededMoney;
  SMG4Visible = true;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::buyPierogiButtonClick(TObject *Sender)
{
 int neededMoney = 15; // temporary variable
 if (money < neededMoney)
  ShowMessage("You do not have enough money to buy this item.\nYou need " +
               IntToStr(neededMoney - money) + "z³ more.");
 if (money >= neededMoney) {
  if (itemCount == 100)
   ShowMessage("Item inventory is full.");
  else {
   itemCount++;
   itemsBox->AddItem("Dumplings", NULL);
   money -= neededMoney;
  }
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::buyBaguetteButtonClick(TObject *Sender)
{
 int neededMoney = 5; // temporary variable
 if (money < neededMoney)
  ShowMessage("You do not have enough money to buy this item.\nYou need " +
               IntToStr(neededMoney - money) + "z³ more.");
 if (money >= neededMoney) {
  if (itemCount == 100)
   ShowMessage("Item inventory is full.");
  else {
   itemCount++;
   itemsBox->AddItem("Baguette", NULL);
   money -= neededMoney;
  }
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::buyPolishFlagButtonClick(TObject *Sender)
{
 int neededMoney = 30; // temporary variable
 if (money < neededMoney)
  ShowMessage("You do not have enough money to buy this item.\nYou need " +
               IntToStr(neededMoney - money) + "z³ more.");
 if (money >= neededMoney) {
  polishFlagBought = true;
  buyPolishFlagButton->Enabled = false;
  polishFlagPrice->Caption = "Sold out";
  money -= neededMoney;
  beniuHappinessDecrease = beniuHappinessDecrease / 2;
  polishVisible = true;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::buyFrenchFriesButtonClick(TObject *Sender)
{
 int neededMoney = 30; // temporary variable
 if (money < neededMoney)
  ShowMessage("You do not have enough money to buy this item.\nYou need " +
               IntToStr(neededMoney - money) + "z³ more.");
 if (money >= neededMoney) {
  if (itemCount == 100)
   ShowMessage("Item inventory is full.");
  else {
   itemCount++;
   itemsBox->AddItem("French fries", NULL);
   money -= neededMoney;
  }
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::useItemClick(TObject *Sender)
{
 for (int i = 0; i < itemsBox->Count; i++) {
  if (itemsBox->Selected[i]) {
   if (itemsBox->Items->Strings[i] == "Dumplings") {
    if (useOnSealand->Checked == true)
     if (sealandHunger + 20 > 112)
      sealandHunger = 112;
     else
      sealandHunger += 20;
    if (useOnBeniu->Checked == true)
     if (beniuHunger + 42 > 112)
      beniuHunger = 112;
     else
      beniuHunger += 20;
    if (rand()%100 < 5 && !beniuCaught) {
     ShowMessage("Beniu1305 has smelled the dumplings and came to your house!");
     beniuCaught = true;
     beniu->Visible = true;
     beniuHappinessBarLabel->Visible = true;
     beniuHungerBarLabel->Visible = true;
     beniuHappinessBar->Visible = true;
     beniuHungerBar->Visible = true;
     useOnBeniu->Visible = true;
    }
    if (useOnBeniu->Checked == true || useOnSealand->Checked == true) {
     itemsBox->Items->Delete(i);
     itemCount--;
    }
    break;
   }
   if (itemsBox->Items->Strings[i] == "Baguette") {
    if (useOnSealand->Checked == true)
     if (sealandHunger + 12.5 > 112)
      sealandHunger = 112;
     else
      sealandHunger += 12.5;
    if (useOnBeniu->Checked == true)
     if (beniuHunger + 83 > 112)
      beniuHunger = 112;
     else
      beniuHunger += 83;
    if (useOnBeniu->Checked == true || useOnSealand->Checked == true) {
     itemsBox->Items->Delete(i);
     itemCount--;
    }
    break;
   }
   if (itemsBox->Items->Strings[i] == "Italian pizza") {
    if (useOnSealand->Checked == true)
     if (sealandHunger + 56 > 112)
      sealandHunger = 112;
     else
      sealandHunger += 56;
     if (useOnBeniu->Checked == true)
      if (beniuHunger + 101 > 112)
       beniuHunger = 112;
      else
       beniuHunger += 101;
     if (useOnStonkFish->Checked == true) {
      sealandHunger = 112;
      sealandHappiness = 112;
      beniuHunger = 112;
      beniuHappiness = 112;
      stonkFishHappiness = 112;
     }
    if (rand()%100 < 25 && !stonkFishCaught) {
     ShowMessage("StonkFish has smelled the pizza and came to your house!");
     stonkFishCaught = true;
     stonkFish->Visible = true;
     stonkFishHappinessBarLabel->Visible = true;
     stonkFishHungerBarLabel->Visible = true;
     stonkFishHappinessBar->Visible = true;
     stonkFishHungerBar->Visible = true;
     useOnStonkFish->Visible = true;
    }
    itemsBox->Items->Delete(i);
    itemCount--;
    break;
   }
   if (itemsBox->Items->Strings[i] == "French fries") {
    if (useOnSealand->Checked == true)
     if (sealandHunger + 25 > 112)
      sealandHunger = 112;
     else
      sealandHunger += 25;
    if (useOnBeniu->Checked == true)
     if (beniuHunger + 79 > 112)
      beniuHunger = 112;
     else
      beniuHunger += 79;
    if (useOnBeniu->Checked == true || useOnSealand->Checked == true) {
     itemsBox->Items->Delete(i);
     itemCount--;
    }
    break;
   }
  }
 }
 /*
  switch (itemsBox->Items->Strings[i]) {
   case Dumplings:
    if (useOnSealand->Checked)
      sealandHunger += 20;
    if (rand()%100 < 5 && !beniuCaught) {
     ShowMessage("Beniu1305 has smelled the dumplings and came to your house!");
     beniuCaught = true;
     // gonna add code later
    }
    break;
   case Baguette:
    if (useOnSealand->Checked)
     sealandHunger += 12.5;
    break;
   case ItalianPizza:
    if (useOnSealand->Checked)
     sealandHunger += 56;
    if (rand()%100 < 25 && !stonkFishCaught) {
     ShowMessage("StonkFish has smelled the pizza and came to your house!");
     stonkFishCaught = true;
     // gonna add code later
    }
    break;
   case FrenchFries:
    if (useOnSealand->Checked)
     sealandHunger += 25;
    break;
   default:
    ShowMessage("Something has gone wrong, please contact vista man.");
  }
 }                                                                 */
}
//---------------------------------------------------------------------------
void __fastcall TForm1::howToPlayButtonClick(TObject *Sender)
{
 exitButton->Visible = false;
 howToPlayButton->Visible = false;
 playButton->Visible = false;
 titleScreenName->Visible = false;
 goBackButton->Visible = true;
 howToPlay->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::goBackButtonClick(TObject *Sender)
{
 exitButton->Visible = true;
 howToPlayButton->Visible = true;
 playButton->Visible = true;
 titleScreenName->Visible = true;
 goBackButton->Visible = false;
 howToPlay->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::useOnSealandClick(TObject *Sender)
{
 useOnBeniu->Checked = false;
 useOnStonkFish->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::useOnBeniuClick(TObject *Sender)
{
 useOnSealand->Checked = false;
 useOnStonkFish->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::useOnStonkFishClick(TObject *Sender)
{
 useOnBeniu->Checked = false;
 useOnSealand->Checked = false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::itemsBoxKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
 if (Key == 13)
  useItemClick(Form1);        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::stonkFishClick(TObject *Sender)
{
 if (workButton->Caption == "Go back home") {
  money += 16;
  if (itemCount < 100) {
   itemsBox->AddItem("Fish", NULL);
   itemCount++;
  }
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::beniuClick(TObject *Sender)
{
 if (beniuHappinessBar->Width < 100)
  beniuHappiness += 12;
 else
  beniuHappiness = 112;
 if (workButton->Caption == "Go back home")
  money += 32;
}
//---------------------------------------------------------------------------

