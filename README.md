Libing-header-file
==================

Libingのjavascript-Objc連携に必要なヘッダー情報

LibingではJavaScriptの関数Libing.UIWebView();を利用することで、UIWebViewの関数を利用することができます。
selfでJavaScriptを実行しているUIWebViewその他JavaScriptで宣言された変数などを引数に与えることができます。

例)
javascript:alert(Libing.UIWebView('[self delegate]'));

このように、命令文は文字列で与えます。
この場合はUIWebViewのデリゲートがアラートに表示されます。
実行してみればわかると思いますが、返り値はObjective-Cにおけるdescriptionの形となっています。
逆に、この結果を変数に格納することで以下のような事も可能になります。

例)
javascript:var d=Libing.UIWebView('[self delegate]');alert(Libing.UIWebView('[d delegate]');

Hide adsアドオンがあれば、self以外の関数も呼ぶことが可能になります。
また、NSArrayとArray()やNSDictionaryとObject()の相互変換も可能となっています。
或いは、以下のように命令しても、同じ結果を得ることができます。

例)
javascript:alert(Libing.UIWebView('[[self delegate] delegate]'));

Objective-Cのドット構文は、JavaScriptの構造体探索と区別がつかないため、利用できない仕様としています。
また、引数毎に複数の命令を与え、一度に実行することも可能です。
この場合、全ての返り値はArrayに格納されます。

現在公開しているヘッダー意外にも、ほしい情報があればメールなどしていただければ対応致します。

headerのコメントは後日対応予定。

Copyright (c) 2014 Nobuo Saito. All rights reserved.