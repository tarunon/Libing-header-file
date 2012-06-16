Libing-header-file
==================

Libingのjavascript-Objc連携に必要なヘッダー情報

LibingではJavaScriptの関数Libing_UIWebView();を利用することで、UIWebViewの関数を利用することができます。
selfでJavaScriptを実行しているUIWebViewその他JavaScriptで宣言された変数などを引数に与えたりすることができます。

例)
javascript:alert(Libing_UIWebView('[self delegate]'));

このように、命令文は文字列で与えます。
この場合はUIWebViewのデリゲートがアラートに表示されます。
実行してみればわかると思いますが、返り値はObjective-Cにおけるdescriptionの形となっています。
逆に、この結果を変数に格納することで以下のような事も可能になります。

例)
javascript:var d=Libing_UIWebView('[self delegate]');alert(Libing_UIWebView('[d tabArray]');

tabArrayはその名の通りタブ列で、現在開かれているタブのインスタンスが含まれています。
Hide adsアドオンがあれば、self以外の関数も呼ぶことが可能になります。
また、この結果から解る通りNSArrayとArray()の相互変換も可能となっています。
或いは、以下のように命令しても、同じ結果を得ることもできます。

例)
javascript:alert(Libing_UIWebView('[[self delegate] tabArray]'));

Objective-Cのドット構文は、JavaScriptの構造体探索と区別がつかないため、利用できない仕様としています。
また、与える命令文をセミコロンで区切ることで、複数命令を一度に実行することも可能です。
この場合、全ての返り値はArrayに格納されます。

現在公開しているヘッダー意外にも、ほしい情報があればメールなどしていただければ対応致します。

Copyright (c) 2012 Nobuo Saito. All rights reserved.