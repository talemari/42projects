<?php 
    class UnholyFactory {
        private $fighters = array();
        public function absorb($type) {
            if (!($type instanceof Fighter))
            {
                print("(Factory can't absorb this, it's not a fighter)\n");
                return ;
            }
            foreach ($this->fighters as $elem)
            {
                if ($elem == $type)
                {
                    print("(Factory already absorbed a fighter of type " . $type->getType() . ")\n");
                    return ;
                }
            }
            $this->fighters[] = $type;
            print("(Factory absorbed a fighter of type " . $type->getType() . ")\n");
        }
        public function fabricate($type) {
            $isvalid = 'NULL';
            $i = -1;
            while ($this->fighters[++$i])
            {
                if ($this->fighters[$i]->getType() == $type)
                {
                    $isvalid = $type;
                    break;
                }
            }
            if ($isvalid != 'NULL')
            {
                print ("(Factory fabricates a fighter of type " . $type . ")\n");
                return $this->fighters[$i];
            }
            else
                print ("(Factory hasn't absorbed any fighter of type " . $type . ")\n");
        }
    }
?>