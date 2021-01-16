type ast;

[@bs.module "reason"] external parseRE : string => ast = "parseRE";
[@bs.module "reason"] external parseREI : string => ast = "parseREI";
[@bs.module "reason"] external parseML : string => ast = "parseML";
[@bs.module "reason"] external parseMLI : string => ast = "parseMLI";
[@bs.module "reason"] external printRE : ast => string = "printRE";
[@bs.module "reason"] external printREI : ast => string = "printREI";
[@bs.module "reason"] external printML : ast => string = "printML";
[@bs.module "reason"] external printMLI : ast => string = "printMLI";
