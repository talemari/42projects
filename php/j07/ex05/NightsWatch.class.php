<?php 
    class NightsWatch  {
        public function recruit($fighter) {
            if ($fighter instanceof IFighter)
                print($fighter::fight());
        }
        public function fight() {
        }
    }
?>